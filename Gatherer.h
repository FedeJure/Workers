#ifndef GATHERER_H_
#define GATHERER_H_     
#include "./Worker.h"
#include "./MaterialQueue.h"
#include "./InventoryQueue.h"
class MaterialQueue;
class Gatherer: public Worker {
    InventoryQueue* inventory;
    MaterialQueue* queue;
    public:
    Gatherer(MaterialQueue& providedQueue,
            InventoryQueue& inventory) : Worker() {
        this->inventory = &inventory;
        this->queue = &providedQueue;
    }
    ~Gatherer() {}
    virtual void work();
};

#endif
