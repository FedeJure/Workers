#ifndef GATHERER_H_
#define GATHERER_H_     
#include "./Worker.h"
#include "./BlockingQueue.h"
class Gatherer: public Worker {
    BlockingQueue* inventory;
    BlockingQueue* queue;

    protected:
    virtual std::vector<QueueRequestDto> requiredMaterials() = 0;

    public:
    Gatherer(BlockingQueue& providedQueue,
            BlockingQueue& inventory);
    ~Gatherer();
    virtual void work();
};

#endif
