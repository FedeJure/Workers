#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "./BlockingQueue.h"
template<typename Entry, typename Processed>class BlockingQueue;

template<typename Entry, typename Processed>
class Worker {
    protected:
    std::thread thread;
    void start() {
        thread = std::thread(&Worker<Entry, Processed>::work, this);
    }

    public:
    Worker() {}
    virtual void waitUntilTerminate() {
        thread.join();
    }

    virtual void work() = 0;
    virtual bool continueCondition(BlockingQueue<Entry, Processed> queue);
    virtual ~Worker() {}
    virtual Processed processMaterials(std::vector<Entry> toProcess);
};

#endif
