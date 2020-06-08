#include <vector>
#include "./Farmer.h"

Farmer::Farmer(BlockingQueue& providedQueue,
    BlockingQueue& repository)
    : Gatherer(providedQueue,repository) {}

std::vector<QueueRequestDto> Farmer::requiredMaterials() {
    std::vector<QueueRequestDto> materials;
    materials.push_back(QueueRequestDto(Wheat, 1));
    return materials;
}
