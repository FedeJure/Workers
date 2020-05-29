#ifndef GATHERER_H_
#define GATHERER_H
#include "./Worker.h"
#include "./BlockingQueue.h"
#include "./BenefitPointRepository.h"
#include "./Inventory.h"
#include "./Material.h"

class Gatherer: public Worker<Material, Material> {
    Inventory* inventory;
    public:
    Gatherer(BlockingQueue<Material, Material>& providedQueue,
            Inventory& inventory) : Worker<Material, Material>(providedQueue) {
        this->inventory = &inventory;
    }
    
    virtual ~Gatherer() {}
    protected:
    virtual void saveWork(Material values);
};

#endif