#ifndef PRODUCER_H_
#define PRODUCER_H_
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
    Producer(InventoryQueue& providedQueue, BenefitPointRepository& repository) {
        this->repository = &repository;
        this->inventory = &providedQueue;
    }
    virtual void work();
    virtual std::vector<std::pair<Material, size_t>> requiredMaterials() = 0;
    virtual bool continueCondition(InventoryQueue& inventory) = 0;
    virtual BenefitPoints processMaterials(std::vector<Material>& materials) = 0;
    virtual ~Producer() {}
};

class Chef: public Producer {
    std::vector<std::pair<Material, size_t>> neededMaterials {
        std::pair<Material, size_t>(Wheat, 2),
        std::pair<Material, size_t>(Coal, 1)
    };
    public:
    Chef(InventoryQueue& providedQueue,
            BenefitPointRepository& repository)
            : Producer(providedQueue,repository) {}
    virtual std::vector<std::pair<Material, size_t>> requiredMaterials();
    virtual bool continueCondition(InventoryQueue& inventory);
    virtual BenefitPoints processMaterials(std::vector<Material>& materials);
};

class Carpenter: public Producer {
    std::vector<std::pair<Material, size_t>> neededMaterials {
        std::pair<Material, size_t>(Wood, 3),
        std::pair<Material, size_t>(Iron, 1)
    };
    public:
    Carpenter(InventoryQueue& providedQueue,
            BenefitPointRepository& repository)
            : Producer(providedQueue,repository) {}
    virtual std::vector<std::pair<Material, size_t>> requiredMaterials();
    virtual bool continueCondition(InventoryQueue& inventory);
    virtual BenefitPoints processMaterials(std::vector<Material>& materials);
};

class Weaponsmith: public Producer {
    std::vector<std::pair<Material, size_t>> neededMaterials {
        std::pair<Material, size_t>(Coal, 2),
        std::pair<Material, size_t>(Iron, 2)
    };
    public:
    Weaponsmith(InventoryQueue& providedQueue,
            BenefitPointRepository& repository)
            : Producer(providedQueue,repository) {}
    virtual std::vector<std::pair<Material, size_t>> requiredMaterials();
    virtual bool continueCondition(InventoryQueue& inventory);
    virtual BenefitPoints processMaterials(std::vector<Material>& materials);
};



#endif
