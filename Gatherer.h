#ifndef GATHERER_H_
#define GATHERER_H_     
#include "./Worker.h"
#include "./MaterialQueue.h"
#include "./InventoryQueue.h"
class MaterialQueue;
class Gatherer: public Worker<Material, Material> {
    InventoryQueue* inventory;
    MaterialQueue* queue;
    public:
    Gatherer(MaterialQueue& providedQueue,
            InventoryQueue& inventory) : Worker<Material, Material>() {
        this->inventory = &inventory;
        this->queue = &providedQueue;
        start();
    }
    ~Gatherer() {
    }
    virtual void work();
    virtual Material processMaterials(std::vector<Material> toProcess) {
        return toProcess.back();
    }
    virtual bool continueCondition(MaterialQueue& queue);
};

#endif
