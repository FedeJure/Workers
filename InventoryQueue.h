#ifndef INVENTORY_QUEUE_H_
#define INVENTORY_QUEUE_H_

#include <map>
#include <mutex>
#include <iostream>
#include <vector>
#include <condition_variable>
#include "./BlockingQueue.h"
#include "./Material.h"
#include "./BenefitPointRepository.h"
class InventoryQueue : BlockingQueue {
    std::mutex notifierMutex;
    std::mutex inventaryMutex;
    std::condition_variable sleepCondition;
    std::map<Material, std::vector<Material>> container;
    bool working = true;
    bool notified = false;

    protected:
    virtual std::vector<Material> extractMaterialsToProcess(
            std::vector<QueueRequestDto>& requests);
    virtual bool hasEnoughMaterials(
         std::vector<QueueRequestDto>& materials);

    public:
    InventoryQueue() {
        container[Wheat];
        container[Wood];
        container[Iron];
        container[Coal];
    }

    virtual void push(const Material material);
    virtual std::vector<Material> pop(
        std::vector<QueueRequestDto>& requiredMaterials);
    virtual void shutdown();
    void printRemainingMaterials();
};

#endif
