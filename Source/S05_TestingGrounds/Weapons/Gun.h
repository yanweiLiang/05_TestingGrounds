// Copyright Nicholas Wilkie 2017

#pragma once

#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class S05_TESTINGGROUNDS_API AGun : public AActor
{
	GENERATED_BODY()
		
	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	class USceneComponent* FP_MuzzleLocation;
		
public:	
	// Sets default values for this actor's properties
	AGun();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABallProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	class USoundBase* FireSound;

	/** AnimMontages to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	class UAnimMontage* FireAnimation1P;
	/** AnimMontages to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	class UAnimMontage* FireAnimation3P;

	class UAnimInstance* AnimInstance1P;
	class UAnimInstance* AnimInstance3P;

	/** Fires a projectile. */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void OnFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
