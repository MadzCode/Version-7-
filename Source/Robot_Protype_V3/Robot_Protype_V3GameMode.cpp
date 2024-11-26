#include "Robot_Protype_V3GameMode.h"
#include "Robot_Protype_V3Character.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineUtils.h"
#include "BP_AI.h" // Include the BP_AI class

ARobot_Protype_V3GameMode::ARobot_Protype_V3GameMode()
{
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }

    // Initialize WaveNumber, EnemyCount, EnemiesRemaining, and EnemyPool
    WaveNumber = 0;
    EnemyCount = 0;
    EnemiesRemaining = 0;
    EnemyPool.Empty();
}

void ARobot_Protype_V3GameMode::BeginPlay()
{
    Super::BeginPlay();

    // Any other initialization logic
}

void ARobot_Protype_V3GameMode::BuildEnemyPool()
{
    // Logic to build the enemy pool
    EnemyPool.Empty();  // Clear the existing pool if any

    // Get the pool size using the new function
    int32 LocalSum = GetPoolSize();

    // Set the remaining enemies count
    EnemiesRemaining = LocalSum;

    UE_LOG(LogTemp, Warning, TEXT("Enemy pool built with %d enemies! LocalSum: %d"), EnemyPool.Num(), LocalSum);
}

int32 ARobot_Protype_V3GameMode::GetPoolSize() const
{
    int32 LocalSum = 0;  // Declare the local variable LocalSum

    // Iterate through all actors in the world and find those that are BP_AI
    for (TActorIterator<AActor> It(GetWorld()); It; ++It)
    {
        if (It->IsA(ABP_AI::StaticClass()))
        {
            // Since GetPoolSize is const, we can't modify EnemyPool here
            LocalSum += 1; // Replace with actual logic if needed
        }
    }

    return LocalSum;
}
