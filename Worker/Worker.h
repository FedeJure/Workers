#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "../Works/WheatQueue.h"

class Worker {
    protected:
    BlockingQueue<int>* queue;
    std::thread thread;

    public:
    Worker(BlockingQueue<int>& providedQueue) : queue(&providedQueue),
                                        thread(&Worker::work, this) {};
    void waitUntilTerminate();
    void work();
    ~Worker() {}
};

#endif