#ifndef PRODUCER_H_
#define PRODUCER_H_
#include "./Worker.h"
#include "./InventoryQueue.h"
#include "./Material.h"
#include "./BenefitPointRepository.h"

class Producer: public Worker {
    BenefitPointRepository* repository;
    InventoryQueue* inventory;
    public:
    Producer(InventoryQueue& providedQueue,
            BenefitPointRepository& repository) : Worker() {
        this->repository = &repository;
        this->inventory = &providedQueue;
    }
    virtual void work();
    virtual std::vector<std::pair<Material, int>> requiredMaterials() = 0;
    virtual bool continueCondition(const InventoryQueue& inventory) = 0;
    virtual BenefitPoints processMaterials(std::vector<Material>& materials) = 0;
    virtual ~Producer() {}
};

class Chef: public Producer {
    public:
    Chef(InventoryQueue& providedQueue,
            BenefitPointRepository& repository) 
            : Producer(providedQueue,repository) {}
    virtual std::vector<std::pair<Material, int>> requiredMaterials();
    virtual bool continueCondition(const InventoryQueue& inventory);
    virtual BenefitPoints processMaterials(std::vector<Material>& materials);
};



#endif