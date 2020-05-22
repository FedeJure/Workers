#ifndef WHEAT_QUEUE_H_
#define WHEAT_QUEUE_H_
#include <mutex>
#include "./BlockingQueue.h"


typedef int Wheat;


class WheatQueue {
    BlockingQueue<Wheat> provider;

    public:
    WheatQueue() {}

    Wheat consume();
    void provide(Wheat count);
    bool isEmpty();
    bool isRunning();
    void shutdown();

    ~WheatQueue() {};
};

#endif