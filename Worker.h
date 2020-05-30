#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "./Maybe.h"

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