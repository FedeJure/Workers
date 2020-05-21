#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "../Works/WheatQueue.h"

class Worker {
    protected:
    WheatQueue* queue;
    std::thread thread;


    public:
    Worker(WheatQueue& providedQueue) : queue(&providedQueue), thread() {};
    void startWorking();
    void work();
    ~Worker() {}
};

#endif