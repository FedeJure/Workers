#ifndef CARPENTER_H_
#define CARPENTER_H_
#include <utility>
#include "./Producer.h"
#include "./InventoryQueue.h"
#include "./BenefitPointRepository.h"

class Carpenter: public Producer {
    public:
    Carpenter(InventoryQueue& providedQueue,
            BenefitPointRepository& repository);
};

#endif
