﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ARPG_AnimNotify.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "输入_动画跳转"))
class ARPG_API UARPG_PlayMontageByInput : public UAnimNotifyState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "动画")
	uint8 bIsReleased : 1;

	UPROPERTY(EditAnywhere, meta = (Bitmask, BitmaskEnum = "EARPG_InputType"), Category = "动画")
	int32 InputType;

	UPROPERTY(EditAnywhere, Category = "动画")
	class UAnimMontage* Montage;
	
	UPROPERTY(EditAnywhere, Category = "动画")
	FName StartSectionName;

	UPROPERTY(EditAnywhere, Category = "动画")
	uint8 bClientMaster : 1;

	virtual void NotifyBegin(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float TotalDuration) override;
	virtual void NotifyTick(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float FrameDeltaTime) override;
	virtual void NotifyEnd(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation) override;

	virtual FString GetNotifyName_Implementation() const override;
	
};