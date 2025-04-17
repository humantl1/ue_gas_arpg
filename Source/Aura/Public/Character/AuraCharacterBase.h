// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	FORCEINLINE UAttributeSet* GetAttributeSet() const { return AttributeSet; }
protected:
	virtual void BeginPlay() override;
	
	// EditAnywhere allows this property to be modified in any instance
	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
	
	// UPROPERTY() macro exposes variables to Unreal Engine's reflection system,
	// enabling features like garbage collection, Blueprint access, and property replication
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	// TObjectPtr is the preferred way to hold UObject pointers in Unreal Engine.
	// it automatically handles pointer dereferencing and null checks,
	// making it safer than raw pointers while maintaining good performance.
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
