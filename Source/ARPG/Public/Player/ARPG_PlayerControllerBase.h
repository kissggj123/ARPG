﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ARPG_LockOnTargetSystem.h"
#include "GenericTeamAgentInterface.h"
#include "ARPG_PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class ARPG_API AARPG_PlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
public:
	AARPG_PlayerControllerBase();

	virtual void Tick(float DeltaSeconds) override;
	
	void GetLifetimeReplicatedProps(TArray< class FLifetimeProperty > & OutLifetimeProps) const override;
public:
	UPROPERTY(EditAnywhere, Category = "锁定系统", meta = (ShowOnlyInnerProperties))
	FARPG_LockOnTargetSystem LockOnTargetSystem;

	UFUNCTION(BlueprintCallable, Category = "锁定系统")
	AActor* GetLockedTarget() const;

	UFUNCTION(BlueprintCallable, Category = "锁定系统")
	void EnableLockOnTargetSystem(bool Enable) { LockOnTargetSystem.bEnableLockOnSystem = Enable; }

	UFUNCTION(BlueprintCallable, Category = "锁定系统")
	bool SetLockedTarget(AActor* Target, const FName& SocketName);

	UFUNCTION(Server, WithValidation, Reliable)
	void SetLockedTarget_ToServer(AActor* Target, const FName& SocketName);
	void SetLockedTarget_ToServer_Implementation(AActor* Target, const FName& SocketName);
	bool SetLockedTarget_ToServer_Validate(AActor* Target, const FName& SocketName) { return true; }

	UFUNCTION(BlueprintCallable, Category = "锁定系统")
	void ClearLockedTarget();

	UFUNCTION(Server, WithValidation, Reliable)
	void ClearLockedTarget_ToServer();
	void ClearLockedTarget_ToServer_Implementation();
	bool ClearLockedTarget_ToServer_Validate() { return true; }

	//返回值代表是否锁定了目标
	UFUNCTION(BlueprintCallable, Category = "锁定系统")
	bool ToggleLockedTarget();

	UFUNCTION(BlueprintCallable, Category = "锁定系统")
	bool InvokeSwitchLockedTarget(bool Left);

public:
	UPROPERTY(VisibleAnywhere, Category = "寻路")
	class UARPG_PathFollowingComponent* PathFollowingComponent;

	UPROPERTY(ReplicatedUsing = OnRep_bIsInPathFollowing)
	uint8 bIsInPathFollowing : 1;
	UFUNCTION()
	void OnRep_bIsInPathFollowing();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "任务")
	class UARPG_GameTaskManager* GameTaskManager;
};
