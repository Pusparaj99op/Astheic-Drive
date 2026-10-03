// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessRoadChunk.h"
#include "EndlessRoadGenerator.h"
#include "ProceduralMeshComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/CollisionProfile.h"
#include "Materials/MaterialInterface.h"
#include "Math/RandomStream.h"

namespace
{
	/** Mesh section indices */
	enum EChunkSection : int32
	{
		Section_Road = 0,
		Section_Shoulder,
		Section_Terrain,
		Section_Rail,
		Section_Marking,
		Section_Concrete,
		Section_Count
	};

	/** Vertex data for one procedural mesh section */
	struct FSectionData
	{
		TArray<FVector> Vertices;
		TArray<int32> Triangles;
		TArray<FVector> Normals;
		TArray<FVector2D> UVs;
		TArray<FLinearColor> Colors;
		TArray<FProcMeshTangent> Tangents;

		/** Adds a triangle, flipping the winding if needed so its front face points along DesiredNormal */
		void AddTriangle(int32 A, int32 B, int32 C, const FVector& DesiredNormal)
		{
			const FVector FaceNormal = FVector::CrossProduct(Vertices[B] - Vertices[A], Vertices[C] - Vertices[A]);

			if (FVector::DotProduct(FaceNormal, DesiredNormal) >= 0.0)
			{
				Triangles.Add(A); Triangles.Add(B); Triangles.Add(C);
			}
			else
			{
				Triangles.Add(A); Triangles.Add(C); Triangles.Add(B);
			}
		}
	};

	/** One row of a strip: the two edge points and the side the surface should face */
	struct FStripRow
	{
		FVector A;
		FVector B;
		FVector Hint;
		double V;
	};

	/** Adds a ribbon of quads between consecutive rows */
	void AddStrip(FSectionData& Data, const TArray<FStripRow>& Rows, float UWidth)
	{
		const int32 NumRows = Rows.Num();
		if (NumRows < 2)
		{
			return;
		}

		const int32 Base = Data.Vertices.Num();

		for (int32 i = 0; i < NumRows; ++i)
		{
			const FStripRow& Row = Rows[i];
			const FVector Along = Rows[FMath::Min(i + 1, NumRows - 1)].A - Rows[FMath::Max(i - 1, 0)].A;
			const FVector Across = Row.B - Row.A;

			FVector Normal = FVector::CrossProduct(Along, Across).GetSafeNormal();
			if (Normal.IsNearlyZero())
			{
				Normal = Row.Hint;
			}
			else if (FVector::DotProduct(Normal, Row.Hint) < 0.0)
			{
				Normal = -Normal;
			}

			const FProcMeshTangent Tangent(Along.GetSafeNormal(), false);

			Data.Vertices.Add(Row.A);
			Data.Vertices.Add(Row.B);
			Data.Normals.Add(Normal);
			Data.Normals.Add(Normal);
			Data.UVs.Add(FVector2D(0.0, Row.V));
			Data.UVs.Add(FVector2D(UWidth, Row.V));
			Data.Colors.Add(FLinearColor::White);
			Data.Colors.Add(FLinearColor::White);
			Data.Tangents.Add(Tangent);
			Data.Tangents.Add(Tangent);
		}

		for (int32 i = 0; i < NumRows - 1; ++i)
		{
			const int32 A0 = Base + i * 2;
			const int32 B0 = A0 + 1;
			const int32 A1 = A0 + 2;
			const int32 B1 = A0 + 3;
			const FVector Desired = Data.Normals[A0] + Data.Normals[A1];

			Data.AddTriangle(A0, B0, B1, Desired);
			Data.AddTriangle(A0, B1, A1, Desired);
		}
	}

	/** Configures an instanced prop component */
	void SetupInstancedComponent(UInstancedStaticMeshComponent* Component, USceneComponent* Parent)
	{
		Component->SetupAttachment(Parent);
		Component->SetMobility(EComponentMobility::Movable);
		Component->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Component->SetGenerateOverlapEvents(false);
		Component->SetCanEverAffectNavigation(false);
	}
}

AEndlessRoadChunk::AEndlessRoadChunk()
{
	PrimaryActorTick.bCanEverTick = false;

	RoadMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("RoadMesh"));
	SetRootComponent(RoadMesh);
	RoadMesh->SetMobility(EComponentMobility::Movable);
	RoadMesh->bUseComplexAsSimpleCollision = true;

	// cook collision synchronously so the car never lands on a road without collision
	RoadMesh->bUseAsyncCooking = false;
	RoadMesh->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	RoadMesh->SetCanEverAffectNavigation(false);

	PalmTrunks = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("PalmTrunks"));
	SetupInstancedComponent(PalmTrunks, RoadMesh);

	PalmLeaves = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("PalmLeaves"));
	SetupInstancedComponent(PalmLeaves, RoadMesh);

	LampPosts = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("LampPosts"));
	SetupInstancedComponent(LampPosts, RoadMesh);

	LampHeads = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("LampHeads"));
	SetupInstancedComponent(LampHeads, RoadMesh);

	Pillars = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Pillars"));
	SetupInstancedComponent(Pillars, RoadMesh);

	Beams = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("Beams"));
	SetupInstancedComponent(Beams, RoadMesh);
}

void AEndlessRoadChunk::ApplyAssets(const FEndlessChunkAssets& Assets)
{
	auto SetMeshAndMaterial = [](UInstancedStaticMeshComponent* Component, UStaticMesh* Mesh, UMaterialInterface* Material, bool bOverrideMaterial)
	{
		if (Component->GetStaticMesh() != Mesh)
		{
			Component->SetStaticMesh(Mesh);
		}

		if (bOverrideMaterial && Material)
		{
			Component->SetMaterial(0, Material);
		}
	};

	// biome meshes keep their own materials, basic shapes get tinted
	if (Assets.PalmMesh)
	{
		SetMeshAndMaterial(PalmTrunks, Assets.PalmMesh, nullptr, false);
	}
	else
	{
		SetMeshAndMaterial(PalmTrunks, Assets.Cylinder, Assets.PalmTrunk, true);
	}

	SetMeshAndMaterial(PalmLeaves, Assets.Sphere, Assets.PalmLeaves, true);

	if (Assets.LampMesh)
	{
		SetMeshAndMaterial(LampPosts, Assets.LampMesh, nullptr, false);
	}
	else
	{
		SetMeshAndMaterial(LampPosts, Assets.Cylinder, Assets.LampPost, true);
	}

	SetMeshAndMaterial(LampHeads, Assets.Cube, Assets.LampPost, true);
	SetMeshAndMaterial(Pillars, Assets.Cylinder, Assets.Concrete, true);
	SetMeshAndMaterial(Beams, Assets.Cube, Assets.Concrete, true);
}

void AEndlessRoadChunk::Build(FEndlessRoadGenerator& Generator, int32 Index, double Length, const FEndlessChunkAssets& Assets)
{
	using namespace EndlessRoadLayout;

	ChunkIndex = Index;

	const double StartDistance = Index * Length;
	const double Step = 250.0;
	const int32 NumRows = FMath::Max(2, FMath::CeilToInt32(Length / Step) + 1);
	const double RowStep = Length / (NumRows - 1);

	// sample the centerline once
	TArray<FEndlessRoadSample> Samples;
	Samples.SetNum(NumRows);
	for (int32 i = 0; i < NumRows; ++i)
	{
		Samples[i] = Generator.SampleAtDistance(StartDistance + i * RowStep);
	}

	// vertices are local to the chunk origin for precision
	const FVector Origin = Samples[0].Location;
	SetActorLocationAndRotation(Origin, FRotator::ZeroRotator, false, nullptr, ETeleportType::TeleportPhysics);

	FSectionData Sections[Section_Count];

	// builds a strip across all rows (or a sub range) from a profile function
	auto BuildStrip = [&](EChunkSection Section, int32 RowBegin, int32 RowEnd, float UWidth, TFunctionRef<void(const FEndlessRoadSample&, FStripRow&)> Profile)
	{
		TArray<FStripRow> Rows;
		Rows.Reserve(RowEnd - RowBegin + 1);

		for (int32 i = RowBegin; i <= RowEnd; ++i)
		{
			FStripRow Row;
			Row.V = Samples[i].Distance / 1000.0;
			Profile(Samples[i], Row);
			Row.A -= Origin;
			Row.B -= Origin;
			Rows.Add(Row);
		}

		AddStrip(Sections[Section], Rows, UWidth);
	};

	const int32 LastRow = NumRows - 1;

	// asphalt
	BuildStrip(Section_Road, 0, LastRow, 4.0f, [](const FEndlessRoadSample& S, FStripRow& Row)
	{
		Row.A = S.Location - S.Right * RoadHalfWidth;
		Row.B = S.Location + S.Right * RoadHalfWidth;
		Row.Hint = S.Up;
	});

	// shoulders
	for (const double Side : { -1.0, 1.0 })
	{
		BuildStrip(Section_Shoulder, 0, LastRow, 1.0f, [Side](const FEndlessRoadSample& S, FStripRow& Row)
		{
			Row.A = S.Location + S.Right * (Side * RoadHalfWidth);
			Row.B = S.Location + S.Right * (Side * (RailOffset + 30.0));
			Row.Hint = S.Up;
		});
	}

	// guard rails: inner face, top, outer face
	const double RailHeight = 80.0;
	const double RailThickness = 30.0;
	for (const double Side : { -1.0, 1.0 })
	{
		BuildStrip(Section_Rail, 0, LastRow, 1.0f, [=](const FEndlessRoadSample& S, FStripRow& Row)
		{
			Row.A = S.Location + S.Right * (Side * RailOffset);
			Row.B = Row.A + S.Up * RailHeight;
			Row.Hint = -S.Right * Side;
		});

		BuildStrip(Section_Rail, 0, LastRow, 1.0f, [=](const FEndlessRoadSample& S, FStripRow& Row)
		{
			Row.A = S.Location + S.Right * (Side * RailOffset) + S.Up * RailHeight;
			Row.B = Row.A + S.Right * (Side * RailThickness);
			Row.Hint = S.Up;
		});

		BuildStrip(Section_Rail, 0, LastRow, 1.0f, [=](const FEndlessRoadSample& S, FStripRow& Row)
		{
			Row.A = S.Location + S.Right * (Side * (RailOffset + RailThickness)) + S.Up * RailHeight;
			Row.B = Row.A - S.Up * (RailHeight + 40.0);
			Row.Hint = S.Right * Side;
		});
	}

	// split the rows into runs of land and bridge, so terrain and deck are only built where needed.
	// each run is extended by one row so neighbouring runs meet without gaps.
	struct FRun { int32 First; int32 Last; bool bBridge; };
	TArray<FRun> Runs;
	{
		int32 RunStart = 0;
		for (int32 i = 1; i <= LastRow; ++i)
		{
			if (Samples[i].bIsBridge != Samples[RunStart].bIsBridge)
			{
				Runs.Add({ RunStart, i, Samples[RunStart].bIsBridge });
				RunStart = i;
			}
		}

		if (RunStart < LastRow)
		{
			Runs.Add({ RunStart, LastRow, Samples[RunStart].bIsBridge });
		}
	}

	const double VergeOffset = 1700.0;
	const double FarOffset = 5500.0;
	const double SeaFloorZ = -400.0;
	const double DeckDepth = 180.0;

	for (const FRun& Run : Runs)
	{
		if (Run.Last <= Run.First)
		{
			continue;
		}

		for (const double Side : { -1.0, 1.0 })
		{
			if (!Run.bBridge)
			{
				// flat verge behind the rail, where the palms stand
				BuildStrip(Section_Terrain, Run.First, Run.Last, 2.0f, [=](const FEndlessRoadSample& S, FStripRow& Row)
				{
					Row.A = S.Location + S.Right * (Side * (RailOffset + RailThickness)) - FVector(0.0, 0.0, 5.0);
					Row.B = Row.A + S.RightFlat * (Side * (VergeOffset - RailOffset)) - FVector(0.0, 0.0, 40.0);
					Row.Hint = FVector::UpVector;
				});

				// slope down into the sea
				BuildStrip(Section_Terrain, Run.First, Run.Last, 8.0f, [=](const FEndlessRoadSample& S, FStripRow& Row)
				{
					const FVector VergeEdge = S.Location + S.Right * (Side * (RailOffset + RailThickness)) + S.RightFlat * (Side * (VergeOffset - RailOffset)) - FVector(0.0, 0.0, 45.0);
					Row.A = VergeEdge;
					Row.B = S.Location + S.RightFlat * (Side * FarOffset);
					Row.B.Z = SeaFloorZ;
					Row.Hint = FVector::UpVector;
				});
			}
			else
			{
				// deck side faces
				BuildStrip(Section_Concrete, Run.First, Run.Last, 1.0f, [=](const FEndlessRoadSample& S, FStripRow& Row)
				{
					Row.A = S.Location + S.Right * (Side * (RailOffset + RailThickness)) - S.Up * 40.0;
					Row.B = Row.A - S.Up * DeckDepth;
					Row.Hint = S.Right * Side;
				});
			}
		}

		if (Run.bBridge)
		{
			// deck underside
			BuildStrip(Section_Concrete, Run.First, Run.Last, 4.0f, [=](const FEndlessRoadSample& S, FStripRow& Row)
			{
				Row.A = S.Location - S.Right * (RailOffset + RailThickness) - S.Up * (40.0 + DeckDepth);
				Row.B = S.Location + S.Right * (RailOffset + RailThickness) - S.Up * (40.0 + DeckDepth);
				Row.Hint = -S.Up;
			});
		}
	}

	// continuous lines: center divider and both edge lines
	const double MarkingLift = 2.0;
	for (const TPair<double, double>& Line : { TPair<double, double>(0.0, 25.0), TPair<double, double>(-680.0, 15.0), TPair<double, double>(680.0, 15.0) })
	{
		const double Offset = Line.Key;
		const double HalfWidth = Line.Value * 0.5;

		BuildStrip(Section_Marking, 0, LastRow, 1.0f, [=](const FEndlessRoadSample& S, FStripRow& Row)
		{
			Row.A = S.Location + S.Right * (Offset - HalfWidth) + S.Up * MarkingLift;
			Row.B = S.Location + S.Right * (Offset + HalfWidth) + S.Up * MarkingLift;
			Row.Hint = S.Up;
		});
	}

	// dashed lane dividers, aligned to world distance so dashes line up across chunks
	const double DashPeriod = 900.0;
	const double DashLength = 300.0;
	const double EndDistance = StartDistance + Length;
	for (double DashStart = FMath::FloorToDouble(StartDistance / DashPeriod) * DashPeriod; DashStart < EndDistance; DashStart += DashPeriod)
	{
		const double From = FMath::Max(DashStart, StartDistance);
		const double To = FMath::Min(DashStart + DashLength, EndDistance);

		if (To - From < 10.0)
		{
			continue;
		}

		const FEndlessRoadSample S0 = Generator.SampleAtDistance(From);
		const FEndlessRoadSample S1 = Generator.SampleAtDistance(To);

		for (const double Offset : { -LaneWidth, LaneWidth })
		{
			TArray<FStripRow> Rows;
			for (const FEndlessRoadSample* S : { &S0, &S1 })
			{
				FStripRow Row;
				Row.A = S->Location + S->Right * (Offset - 7.5) + S->Up * MarkingLift - Origin;
				Row.B = S->Location + S->Right * (Offset + 7.5) + S->Up * MarkingLift - Origin;
				Row.Hint = S->Up;
				Row.V = S->Distance / 1000.0;
				Rows.Add(Row);
			}

			AddStrip(Sections[Section_Marking], Rows, 1.0f);
		}
	}

	// upload the sections
	RoadMesh->ClearAllMeshSections();

	UMaterialInterface* SectionMaterials[Section_Count] = { Assets.Road, Assets.Shoulder, Assets.Terrain, Assets.Rail, Assets.Marking, Assets.Concrete };

	for (int32 SectionIndex = 0; SectionIndex < Section_Count; ++SectionIndex)
	{
		FSectionData& Data = Sections[SectionIndex];

		if (Data.Triangles.Num() == 0)
		{
			continue;
		}

		const bool bCollision = SectionIndex != Section_Marking;
		RoadMesh->CreateMeshSection_LinearColor(SectionIndex, Data.Vertices, Data.Triangles, Data.Normals, Data.UVs, Data.Colors, Data.Tangents, bCollision);
		RoadMesh->SetMaterial(SectionIndex, SectionMaterials[SectionIndex]);
	}

	ApplyAssets(Assets);
	BuildProps(Generator, StartDistance, Length, Assets);

	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}

void AEndlessRoadChunk::BuildProps(FEndlessRoadGenerator& Generator, double StartDistance, double Length, const FEndlessChunkAssets& Assets)
{
	using namespace EndlessRoadLayout;

	PalmTrunks->ClearInstances();
	PalmLeaves->ClearInstances();
	LampPosts->ClearInstances();
	LampHeads->ClearInstances();
	Pillars->ClearInstances();
	Beams->ClearInstances();

	const double EndDistance = StartDistance + Length;

	// deterministic scatter per chunk
	FRandomStream Random(int32(uint32(Assets.Seed) * 92821u + uint32(ChunkIndex) * 7919u + 17u));

	// palms on both verges
	for (const double Side : { -1.0, 1.0 })
	{
		double Distance = StartDistance + Random.FRandRange(0.0f, Assets.PalmSpacing);

		while (Distance < EndDistance)
		{
			const FEndlessRoadSample S = Generator.SampleAtDistance(Distance);

			if (!S.bIsBridge)
			{
				const double Lateral = Random.FRandRange(1250.0f, 1600.0f);
				const FVector Base = S.Location + S.RightFlat * (Side * Lateral) - FVector(0.0, 0.0, 40.0);
				const FRotator Yaw(0.0, Random.FRandRange(0.0f, 360.0f), 0.0);
				const double Height = Random.FRandRange(700.0f, 1000.0f);

				if (Assets.PalmMesh)
				{
					PalmTrunks->AddInstance(FTransform(Yaw, Base, FVector(Height / 850.0)), true);
				}
				else
				{
					// basic shapes are 100 cm with a centered pivot
					PalmTrunks->AddInstance(FTransform(Yaw, Base + FVector(0.0, 0.0, Height * 0.5), FVector(0.35, 0.35, Height / 100.0)), true);
					PalmLeaves->AddInstance(FTransform(Yaw, Base + FVector(0.0, 0.0, Height), FVector(4.5, 4.5, 1.1)), true);
				}
			}

			Distance += Assets.PalmSpacing * Random.FRandRange(0.6f, 1.4f);
		}
	}

	// street lamps on the right rail, aligned to world distance
	for (double Distance = FMath::CeilToDouble(StartDistance / Assets.LampSpacing) * Assets.LampSpacing; Distance < EndDistance; Distance += Assets.LampSpacing)
	{
		const FEndlessRoadSample S = Generator.SampleAtDistance(Distance);
		const FVector Base = S.Location + S.Right * (RailOffset + 15.0);
		const FRotator Rot = FRotationMatrix::MakeFromXY(S.Forward, S.Right).Rotator();

		if (Assets.LampMesh)
		{
			LampPosts->AddInstance(FTransform(Rot, Base), true);
		}
		else
		{
			const double PostHeight = 900.0;
			LampPosts->AddInstance(FTransform(Rot, Base + FVector(0.0, 0.0, PostHeight * 0.5), FVector(0.2, 0.2, PostHeight / 100.0)), true);
			LampHeads->AddInstance(FTransform(Rot, Base + FVector(0.0, 0.0, PostHeight) - S.RightFlat * 120.0, FVector(0.5, 2.6, 0.15)), true);
		}
	}

	// bridge pillars and cross beams
	for (double Distance = FMath::CeilToDouble(StartDistance / Assets.PillarSpacing) * Assets.PillarSpacing; Distance < EndDistance; Distance += Assets.PillarSpacing)
	{
		const FEndlessRoadSample S = Generator.SampleAtDistance(Distance);

		if (!S.bIsBridge)
		{
			continue;
		}

		const double BottomZ = -600.0;
		const double TopZ = S.Location.Z - 220.0;
		const double Height = FMath::Max(TopZ - BottomZ, 100.0);
		const FRotator Yaw(0.0, FMath::RadiansToDegrees(S.Heading), 0.0);

		for (const double Side : { -1.0, 1.0 })
		{
			FVector Base = S.Location + S.RightFlat * (Side * 600.0);
			Base.Z = BottomZ + Height * 0.5;
			Pillars->AddInstance(FTransform(Yaw, Base, FVector(2.2, 2.2, Height / 100.0)), true);
		}

		FVector BeamCenter = S.Location;
		BeamCenter.Z = TopZ - 60.0;
		Beams->AddInstance(FTransform(Yaw, BeamCenter, FVector(2.0, 16.0, 1.2)), true);
	}
}

void AEndlessRoadChunk::Deactivate()
{
	ChunkIndex = INDEX_NONE;

	RoadMesh->ClearAllMeshSections();
	PalmTrunks->ClearInstances();
	PalmLeaves->ClearInstances();
	LampPosts->ClearInstances();
	LampHeads->ClearInstances();
	Pillars->ClearInstances();
	Beams->ClearInstances();

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}
