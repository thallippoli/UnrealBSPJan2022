// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT2_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure)
	int32 GetValue() const
	{ 
		//PrivateVar = 0;
		return PrivateVar * 2;	
	}
	
	UFUNCTION(BlueprintCallable)
	int32 GetValueImpure()
	{ 
		//PrivateVar = 0;
		return PrivateVar * 2;	
	}

	UFUNCTION(BlueprintImplementableEvent)
	void MyEvent();

	const int foo = 42;
public:	
	/// Indicates that this property can be edited by property windows in the editor
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int EditAnywhere = 0;
	
	/// Indicates that this property can be edited by property windows, but only on instances, not on archetypes
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	int EditInstanceOnly = 0;

	/// Indicates that this property can be edited by property windows, but only on archetypes
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int EditDefaultsOnly = 0;

	/// Indicates that this property is visible in property windows, but cannot be edited at all
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int VisibleAnywhere = 0;

	/// Indicates that this property is only visible in property windows for instances, not for archetypes, and cannot be edited
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	int VisibleInstanceOnly = 0;

	/// Indicates that this property is only visible in property windows for archetypes, and cannot be edited
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	int VisibleDefaultsOnly = 0;

	UPROPERTY(BlueprintReadWrite)
	int ReadWrite = 0;

private:
	//UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	int PrivateVar = 42;
};
