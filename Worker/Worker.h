#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "../Works/WheatQueue.h"

class Worker {
    protected:
    const WheatQueue* queue;
    std::thread thread;


    public:
    Worker(const WheatQueue& providedQueue) : queue(&providedQueue), thread() {};
    void startWorking();
    static void work();

    ~Worker() {}
};

#endif