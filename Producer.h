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
    virtual std::vector<std::pair<Material, int>> requiredMaterials();
    virtual bool continueCondition(const InventoryQueue& inventory);
    virtual BenefitPoints processMaterials(std::vector<Material>& materials);
    virtual ~Producer() {}
};

class Chef: public Producer {
    virtual std::vector<std::pair<Material, int>> requiredMaterials();
    virtual bool continueCondition(const InventoryQueue& inventory);
    virtual BenefitPoints processMaterials(std::vector<Material>& materials);
};



#endif