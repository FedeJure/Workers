#ifndef PRODUCER_H_
#define PRODUCER_H_
#include "./Worker.h"
#include "./BlockingQueue.h"
#include "./Inventory.h"
#include "./Material.h"
#include "./BenefitPointRepository.h"

class Producer: public Worker<Material, BenefitPoints> {
    BenefitPointRepository* repository;
    public:
    Producer(BlockingQueue<Material, BenefitPoints>& providedQueue,
            BenefitPointRepository& repository) : Worker<Material, BenefitPoints>(providedQueue) {
        this->repository = &repository;
    }
    
    virtual ~Producer() {}
    protected:
    virtual void saveWork(BenefitPoints values);
};


#endif