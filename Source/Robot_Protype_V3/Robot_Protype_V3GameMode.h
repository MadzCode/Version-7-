#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Robot_Protype_V3GameMode.generated.h"

UCLASS()
class ROBOT_PROTYPE_V3_API ARobot_Protype_V3GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ARobot_Protype_V3GameMode();

    // Function to build enemy pool
    UFUNCTION(BlueprintCallable, Category = "Pool")
    void BuildEnemyPool();

    // Function to get the pool size
    UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Pool")
    int32 GetPoolSize() const;

protected:
    virtual void BeginPlay() override;

private:
    // Variables to track the wave number, enemy count, and enemies remaining
    int32 WaveNumber;
    int32 EnemyCount;
    int32 EnemiesRemaining;

    TArray<AActor*> EnemyPool;
};
