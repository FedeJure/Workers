#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "./InventoryQueue.h"
#include "./Maybe.h"
#include "./Material.h"

class Worker {
    protected:
    std::thread thread;

    public:
    Worker() : thread(&Worker::work, this) {}
    virtual void waitUntilTerminate();
    virtual void work() = 0;
    protected:
};

#endif