#ifndef GATHERER_H_
#define GATHERER_H

#include "./Worker.h"
#include "./Inventory.h"
#include "./Material.h"

class Gatherer {
    std::thread thread;
    BlockingQueue<Material, Material>* queue;
    Inventory* inventory;

    void saveWork(Material value);

    public:
    Gatherer(BlockingQueue<Material, Material>& providedQueue,
            Inventory& inventory) :
        thread(&Gatherer::work, this){
            this->queue =&providedQueue;
            this->inventory = &inventory;
        }
    void work();

    void waitUntilTerminate() {
        this->thread.join();
    }
};

#endif