#include "Weaponsmith.h"

Weaponsmith::Weaponsmith(InventoryQueue& providedQueue,
        BenefitPointRepository& repository)
        : Producer(providedQueue,repository,
        {
            std::pair<Material, size_t>(Coal, 2),
            std::pair<Material, size_t>(Iron, 2)
        },
        WeaponsmithPoints) {}