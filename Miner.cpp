#include <vector>
#include "./Miner.h"

Miner::Miner(BlockingQueue& providedQueue,
    BlockingQueue& repository)
    : Gatherer(providedQueue,repository) {}

std::vector<QueueRequestDto> Miner::requiredMaterials() {
    std::vector<QueueRequestDto> materials;
    materials.push_back(QueueRequestDto(Coal, 1));
    return materials;
}
