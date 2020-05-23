#ifndef WHEAT_QUEUE_H_
#define WHEAT_QUEUE_H_
#include <mutex>
#include "./BlockingQueue.h"


typedef int Wheat;


class WheatQueue {
    BlockingQueue<Wheat> provider;

    public:
    WheatQueue() {}
    Maybe<Wheat> consume();
    void provide(Wheat count);
    void shutdown();
    ~WheatQueue() {};
};

#endif