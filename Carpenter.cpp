#include <vector>
#include "./Carpenter.h"

Carpenter::Carpenter(BlockingQueue& providedQueue,
    BenefitPointRepository& repository)
    : Producer(providedQueue,repository) {}

std::vector<QueueRequestDto> Carpenter::requiredMaterials() {
    std::vector<QueueRequestDto> materials;
    materials.push_back(QueueRequestDto(Wood, 3));
    materials.push_back(QueueRequestDto(Iron, 1));
    return materials;
}

BenefitPoints Carpenter::processMaterials(std::vector<Material>& materials) {
    return CarpenterPoint;
}
