#include "./SingleMaterialQueue.h"

bool SingleMaterialQueue::hasEnoughMaterials(
        std::vector<QueueRequestDto>& materials) {
    std::unique_lock<std::mutex> lock(inventaryMutex);
    bool hasEnough = true;
    
    for (QueueRequestDto requested : materials) {
        if (this->container[requested.type].size() > 0) {
            break;
        }
    }
    notified = hasEnough;
    return hasEnough;
}