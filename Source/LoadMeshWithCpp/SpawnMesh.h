// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "SpawnMesh.generated.h"

UCLASS()
class LOADMESHWITHCPP_API ASpawnMesh : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnMesh();
    
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    /** Set the name of the asset you want to load*/
    UPROPERTY(EditAnywhere, Category = "MeshLoading")
    FString AssetName;
    
    /** Set the version number of the asset*/
    UPROPERTY(EditAnywhere, Category = "MeshLoading")
    int VersionNumber = 1;
};
