#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "../Works/WheatQueue.h"

class Worker {
    protected:
    WheatQueue* queue;
    std::mutex m;
    std::thread thread;
    std::condition_variable codition;
    bool notified = false;



    public:
    Worker(WheatQueue& providedQueue) : queue(&providedQueue),
                                        thread(&Worker::work, this) {};
    void waitUntilTerminate();
    void work();
    ~Worker() {}
};

#endif