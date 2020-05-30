#ifndef GATHERER_H_
#define GATHERER_H
#include "./Worker.h"
#include "./MaterialQueue.h"
#include "./InventoryQueue.h"

class Gatherer: public Worker {
    InventoryQueue* inventory;
    MaterialQueue* queue;
    public:
    Gatherer(MaterialQueue& providedQueue,
            InventoryQueue& inventory) : Worker() {
        this->inventory = &inventory;
        this->queue = &providedQueue;
    }
    virtual void work();
    virtual ~Gatherer() {}
};

#endif