#ifndef CHEF_H_
#define CHEF_H_
#include <utility>
#include "./Producer.h"
#include "./InventoryQueue.h"
#include "./BenefitPointRepository.h"

class Chef: public Producer {
    public:
    Chef(InventoryQueue& providedQueue, BenefitPointRepository& repository);
};

#endif
