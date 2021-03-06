﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action/XD_DispatchableActionBase.h"
#include "ARPG_DA_PlayMontage.generated.h"

class UAnimMontage;

/**
 * 
 */
UCLASS(meta = (DisplayName = "播放蒙太奇"))
class ARPG_API UARPG_DA_PlayMontage : public UXD_DispatchableActionBase
{
	GENERATED_BODY()
public:
	bool IsActionValid() const override;
	void WhenActionActived() override;

	void WhenActionAborted() override;
	void WhenActionDeactived() override;
	void WhenActionFinished() override;
public:
	UPROPERTY(SaveGame, BlueprintReadOnly, meta = (ExposeOnSpawn = "true"))
	TSoftObjectPtr<APawn> Pawn;

	UPROPERTY(SaveGame, BlueprintReadOnly, meta = (ExposeOnSpawn = "true"))
	UAnimMontage* MontageToPlay;

	//当行为被打断时播放的Montage
	UPROPERTY(SaveGame, BlueprintReadOnly, meta = (ExposeOnSpawn = "true"))
	UAnimMontage* WhenAbortedMontage;
protected:
	UPROPERTY(SaveGame, meta = (DisplayName = "当播放结束"))
	FOnDispatchableActionFinishedEvent WhenPlayFinished;

	void WhenMontagePlayFinished(UAnimMontage* Montage, bool bInterrupted);

	void WhenAbortPlayFinished(UAnimMontage* Montage, bool bInterrupted);
};
