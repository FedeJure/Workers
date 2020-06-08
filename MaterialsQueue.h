#ifndef MATERIALS_QUEUE_H_
#define MATERIALS_QUEUE_H_

#include <map>
#include <mutex>
#include <iostream>
#include <vector>
#include <condition_variable>
#include "./BlockingQueue.h"
#include "./Material.h"
class MaterialsQueue : public BlockingQueue {
    protected:
    std::mutex notifierMutex;
    std::mutex inventaryMutex;
    std::condition_variable sleepCondition;
    bool working = true;
    bool notified = false;
    std::map<Material, std::vector<Material>> container;
    virtual std::vector<Material> extractMaterialsToProcess(
            std::vector<QueueRequestDto>& requests);
    virtual bool hasEnoughMaterials(
         std::vector<QueueRequestDto>& materials);

    public:
    virtual void push(const Material material);
    virtual std::vector<Material> pop(
        std::vector<QueueRequestDto>& requiredMaterials);
    virtual void shutdown();
};

#endif
