#ifndef PRODUCER_H_
#define PRODUCER_H_
#include <vector>
#include "./InventoryQueue.h"
#include "./Worker.h"
#include "./Material.h"
#include "./BenefitPointRepository.h"
class Producer: public Worker {
    BenefitPointRepository* repository;
    InventoryQueue* inventory;

    protected:
    virtual std::vector<QueueRequestDto> requiredMaterials() = 0;
    virtual BenefitPoints processMaterials(std::vector<Material>& materials)
        = 0;
    
    public:
    Producer(InventoryQueue& providedQueue,
            BenefitPointRepository& repository);
    virtual void work();
    ~Producer();
};



#endif
