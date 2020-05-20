#ifndef WHEAT_QUEUE_H_
#define WHEAT_QUEUE_H_
#include <mutex>
#include "./WorkProvider.h"



class WheatQueue {
    WorkProvider provider;

    public:
    WheatQueue() : provider() {}

    virtual int consume();
    virtual void provide(int count);

    ~WheatQueue() {};
};

#endif