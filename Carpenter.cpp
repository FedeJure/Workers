#include "./Carpenter.h"

Carpenter::Carpenter(InventoryQueue& providedQueue,
        BenefitPointRepository& repository)
        : Producer(providedQueue,repository,
        {
            std::pair<Material, size_t>(Wood, 3),
            std::pair<Material, size_t>(Iron, 1)
        },
        CarpenterPoint) {}