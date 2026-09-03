#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MHW_ActorComponentBase.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MHWR_REBUILD_API UMHW_BaseActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMHW_BaseActorComponent();
};
