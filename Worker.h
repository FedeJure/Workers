#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "./Maybe.h"

class Worker {
    protected:
    std::thread thread;
    void start();

    public:
    Worker();
    virtual void waitUntilTerminate();
    virtual void work() = 0;
    virtual ~Worker();
};

#endif
