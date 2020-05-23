#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "./Inventory.h"
#include "./WheatQueue.h"

class Worker {
    protected:
    BlockingQueue<int>* queue;
    std::thread thread;
    Inventory* inventory;

    public:
    Worker(BlockingQueue<int>& providedQueue, Inventory& inventory) 
                    : queue(&providedQueue), thread(&Worker::work, this) {
                        this->inventory = &inventory;
                    };
    void waitUntilTerminate();
    void work();
    ~Worker() {}
};

#endif