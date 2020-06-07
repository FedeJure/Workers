#ifndef WEAPONSMITH_H_
#define WEAPONSMITH_H_
#include <utility>
#include "./Producer.h"
#include "./InventoryQueue.h"
#include "./BenefitPointRepository.h"

class Weaponsmith: public Producer {
    public:
    Weaponsmith(InventoryQueue& providedQueue,
            BenefitPointRepository& repository);
};

#endif
