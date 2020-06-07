#include <vector>
#include "Weaponsmith.h"

Weaponsmith::Weaponsmith(InventoryQueue& providedQueue,
    BenefitPointRepository& repository)
    : Producer(providedQueue,repository) {}

std::vector<QueueRequestDto> Weaponsmith::requiredMaterials() {
    std::vector<QueueRequestDto> materials;
    materials.push_back(QueueRequestDto(Iron, 2));
    materials.push_back(QueueRequestDto(Coal, 2));
    return materials;
}

BenefitPoints Weaponsmith::processMaterials(std::vector<Material>& materials) {
    return WeaponsmithPoints;
}
