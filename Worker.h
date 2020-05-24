#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "./Inventory.h"
#include "./Maybe.h"
#include "./Material.h"
#include "./BlockingQueue.h"

class Worker {
    protected:
    BlockingQueue<Material>* queue;
    std::thread thread;
    Inventory* inventory;

    public:
    Worker(BlockingQueue<Material>& providedQueue, Inventory& inventory) 
                    : queue(&providedQueue), thread(&Worker::work, this) {
                        this->inventory = &inventory;
                    };
    void waitUntilTerminate();
    void work();
    ~Worker() {}
};

#endif