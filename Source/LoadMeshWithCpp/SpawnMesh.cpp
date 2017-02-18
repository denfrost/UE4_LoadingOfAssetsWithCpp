// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadMeshWithCpp.h"
#include "SpawnMesh.h"


// Sets default values
ASpawnMesh::ASpawnMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

//    RootComponent = CreateDefaultSubobject<USphereComponent>(TEXT("MySphere"));
    
    static ConstructorHelpers::FObjectFinder<UStaticMesh>
    StaticMesh(TEXT("StaticMesh'/Game/Meshes/Pil_X_Fram_Hump_Z_Opp.Pil_X_Fram_Hump_Z_Opp'"));
    
    UStaticMeshComponent* StaticMeshComp = GetStaticMeshComponent();
    
    StaticMeshComp->SetStaticMesh(StaticMesh.Object);
//    WeaponMesh->SetStaticMesh(StaticMesh1.Object);

//  WeaponMesh->SetupAttachment(RootComponent);
//    if (WeaponMesh)
//    {
//    SetRootComponent(WeaponMesh);
//    }
//    
}

//void ASpawnMesh::OnConstruction(const FTransform& Transform)
//{
//    WeaponMesh->SetupAttachment(RootComponent);
//}

// Called when the game starts or when spawned
void ASpawnMesh::BeginPlay()
{
	Super::BeginPlay();
    
	
}

// Called every frame
void ASpawnMesh::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

