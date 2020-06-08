#ifndef CHEF_H_
#define CHEF_H_
#include <vector>
#include "./Producer.h"
#include "./Material.h"
#include "./BenefitPointRepository.h"

class Chef: public Producer {
    protected:
    virtual std::vector<QueueRequestDto> requiredMaterials();
    virtual BenefitPoints processMaterials(std::vector<Material>& materials);
    
    public:
    Chef(BlockingQueue& providedQueue, BenefitPointRepository& repository);
};

#endif
