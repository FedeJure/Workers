#ifndef CARPENTER_H_
#define CARPENTER_H_
#include <vector>
#include "./Producer.h"
#include "./InventoryQueue.h"
#include "./BenefitPointRepository.h"

class Carpenter: public Producer {
    protected:
    virtual std::vector<QueueRequestDto> requiredMaterials();
    virtual BenefitPoints processMaterials(std::vector<Material>& materials);

    public:
    Carpenter(InventoryQueue& providedQueue,
            BenefitPointRepository& repository);
};

#endif
