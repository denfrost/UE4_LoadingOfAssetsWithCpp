// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadMeshWithCpp.h"
#include "SpawnMesh.h"
#include <String>


// Sets default values
ASpawnMesh::ASpawnMesh()
{
    //Set the default mesh:
    static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Game/Meshes/Default.Default'"));
    UStaticMeshComponent* StaticMeshComp = GetStaticMeshComponent();
    StaticMeshComp->SetStaticMesh(StaticMesh.Object);

}

void ASpawnMesh::BeginPlay()
{
    Super::BeginPlay();
    
    /**Dynamic loading of a mesh during startup*/
    
    //Path name - /Game/ = the real folder "Content"
    std::string PathName = "StaticMesh'/Game/Meshes/";
    
    //Making the assetname with version number
    FString Asset(AssetName + FString::FromInt(VersionNumber));
    
    //The full path. Asset name have to be repeated with a . between
    FString AssetFullPath(PathName.c_str() + Asset + "." + Asset + "'");
    UE_LOG(LogTemp, Warning, TEXT("Loading Asset Named %s"), *AssetFullPath);
    
    //Loading the mesh
    UStaticMesh* StaticMesh = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, *AssetFullPath));

    //Testing if successfull - setting mesh or printing error
    if (StaticMesh)
    {
        UStaticMeshComponent* StaticMeshComp = GetStaticMeshComponent();
        StaticMeshComp->SetStaticMesh(StaticMesh);
    }
    else{
        UE_LOG(LogTemp, Error, TEXT("No static mesh loaded"));
    }
}
