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
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
    
//    virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditAnywhere)
    UStaticMeshComponent *WeaponMesh;
	
};
