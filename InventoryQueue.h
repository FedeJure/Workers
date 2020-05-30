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
    std::condition_variable sleepCondition;
    std::map<Material, std::vector<Material>> container;
    bool working = true;
    bool notified = false;


    public:
    InventoryQueue() {
        container[Wheat] = std::vector<Material>();
        container[Wood] = std::vector<Material>();
        container[Iron] = std::vector<Material>();
        container[Coal] = std::vector<Material>();
    }

    void push(const Material material);
    virtual Maybe<BenefitPoints> pop(Producer& worker);
    void shutdown();

    private:
    void extractMaterialsToProcess(
                std::vector<std::pair<Material, int>>& materials,
                std::vector<Material>& toProcess);

};

#endif