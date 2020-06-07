#ifndef PRODUCER_H_
#define PRODUCER_H_
#include <initializer_list>
#include <utility>
#include <vector>
#include "./InventoryQueue.h"
#include "./Worker.h"
#include "./Material.h"
#include "./BenefitPointRepository.h"
class InventoryQueue;
class Producer: public Worker {
    BenefitPointRepository* repository;
    InventoryQueue* inventory;
    std::vector<std::pair<Material, size_t>> neededMaterials;
    BenefitPoints pointsOnProcess;
    public:
    Producer(InventoryQueue& providedQueue, BenefitPointRepository& repository,
        std::initializer_list<std::pair<Material, size_t>> materials,
        BenefitPoints points);
    virtual void work();
    virtual std::vector<std::pair<Material, size_t>> requiredMaterials();
    virtual bool continueCondition(InventoryQueue& inventory);
    virtual BenefitPoints processMaterials(std::vector<Material>& materials);
    ~Producer();
};



#endif
