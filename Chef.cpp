#include "./Chef.h"

Chef::Chef(InventoryQueue& providedQueue,
    BenefitPointRepository& repository)
    : Producer(providedQueue,repository,
    {
        std::pair<Material, size_t>(Wheat, 2),
        std::pair<Material, size_t>(Coal, 1)
    },
    ChefPoint) {}