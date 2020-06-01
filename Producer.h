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
        BenefitPoints points): 
        neededMaterials(materials), pointsOnProcess(points) {
        this->repository = &repository;
        this->inventory = &providedQueue;
        start();
    }
    virtual void work();
    virtual std::vector<std::pair<Material, size_t>> requiredMaterials();
    virtual bool continueCondition(InventoryQueue& inventory);
    virtual BenefitPoints processMaterials(std::vector<Material>& materials);
    ~Producer() {}
};

class Chef: public Producer {
    public:
    Chef(InventoryQueue& providedQueue,
            BenefitPointRepository& repository)
            : Producer(providedQueue,repository,
                    {
                        std::pair<Material, size_t>(Wheat, 2),
                        std::pair<Material, size_t>(Coal, 1)
                    },
                    ChefPoint) {}
};

class Carpenter: public Producer {
    public:
    Carpenter(InventoryQueue& providedQueue,
            BenefitPointRepository& repository)
            : Producer(providedQueue,repository,
            {
                std::pair<Material, size_t>(Wood, 3),
                std::pair<Material, size_t>(Iron, 1)
            },
            CarpenterPoint) {}
};

class Weaponsmith: public Producer {
    public:
    Weaponsmith(InventoryQueue& providedQueue,
            BenefitPointRepository& repository)
            : Producer(providedQueue,repository,
            {
                std::pair<Material, size_t>(Coal, 2),
                std::pair<Material, size_t>(Iron, 2)
            },
            WeaponsmithPoints) {}
};



#endif
