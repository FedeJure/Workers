#include <vector>
#include "./Chef.h"

Chef::Chef(InventoryQueue& providedQueue,
    BenefitPointRepository& repository)
    : Producer(providedQueue,repository) {}

std::vector<QueueRequestDto> Chef::requiredMaterials() {
    std::vector<QueueRequestDto> materials;
    materials.push_back(QueueRequestDto(Wheat, 2));
    materials.push_back(QueueRequestDto(Coal, 1));
    return materials;
}

BenefitPoints Chef::processMaterials(std::vector<Material>& materials) {
    return ChefPoint;
}
