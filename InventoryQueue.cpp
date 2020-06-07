#include <vector>
#include "./InventoryQueue.h"

bool InventoryQueue::hasEnoughMaterials(
    std::vector<QueueRequestDto>& materials) {
    std::unique_lock<std::mutex> lock(inventaryMutex);
    bool hasEnough = true;
    
    for (QueueRequestDto requested : materials) {
        if (this->container[requested.type].size() < requested.count) {
            hasEnough = false;
            fflush(stdout);
            break;
        }
    }
    notified = hasEnough;
    return hasEnough;
}

std::vector<Material> InventoryQueue::pop(
    std::vector<QueueRequestDto>& requiredMaterials) {
    std::unique_lock<std::mutex> lock(notifierMutex);

    while (!hasEnoughMaterials(requiredMaterials)) {
        if (!working) {
            return std::vector<Material>();
        }
        while (!notified) {
            sleepCondition.wait(lock);
            if (!working) return std::vector<Material>();
        }
    }
    return extractMaterialsToProcess(requiredMaterials);
}


void InventoryQueue::push(const Material material) {
    std::unique_lock<std::mutex> lock(notifierMutex);
    container[material].push_back(material);
    sleepCondition.notify_all();
    notified = true;
}
void InventoryQueue::shutdown() {
    std::unique_lock<std::mutex> lock(notifierMutex);
    working = false;
    sleepCondition.notify_all();
}

std::vector<Material> InventoryQueue::extractMaterialsToProcess(
                std::vector<QueueRequestDto>& materials) {
    std::unique_lock<std::mutex> lock(inventaryMutex);
    std::vector<Material> extracted;
    for (QueueRequestDto requested : materials) {
        while (requested.count > 0) {
            extracted.push_back(container[requested.type].back());
            container[requested.type].pop_back();
            requested.count--;
        }
    }
    return extracted;
}


void InventoryQueue::printRemainingMaterials() {
    std::cout<<"Recursos restantes:\n";
    std::cout<<"  - Trigo: "<<container[Wheat].size()<<"\n";
    std::cout<<"  - Madera: "<<container[Wood].size()<<"\n";
    std::cout<<"  - Carbon: "<<container[Coal].size()<<"\n";
    std::cout<<"  - Hierro: "<<container[Iron].size()<<"\n\n";
    fflush(stdout);
}
