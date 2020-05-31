#ifndef INVENTORY_QUEUE_H_
#define INVENTORY_QUEUE_H_

#include <map>
#include <mutex>
#include <iostream>
#include <vector>
#include <utility>
#include <condition_variable>
#include "./Material.h"
#include "./BenefitPointRepository.h"
#include "./Producer.h"
#include "./Maybe.h"
class Producer;
class InventoryQueue {
    std::mutex notifierMutex;
    std::mutex inventaryMutex;
    std::condition_variable sleepCondition;
    std::map<Material, std::vector<Material>> container;
    bool working = true;
    bool notified = false;

    void extractMaterialsToProcess(
            std::vector<std::pair<Material, size_t>>& materials,
            std::vector<Material>& toProcess);

    public:
    InventoryQueue() {
        container[Wheat];
        container[Wood];
        container[Iron];
        container[Coal];
    }

    void push(const Material material);
    virtual Maybe<BenefitPoints> pop(Producer& worker);
    void shutdown();
    bool hasEnoughMaterials(
        std::vector<std::pair<Material, size_t>>& materials);
    void printRemainingMaterials();
};

#endif
