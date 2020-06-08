#ifndef MINER_H_
#define MINER_H_
#include <vector>
#include "./Gatherer.h"
#include "./BlockingQueue.h"

class Miner: public Gatherer{
    protected:
    virtual std::vector<QueueRequestDto> requiredMaterials();
    
    public:
    Miner(BlockingQueue& providedQueue, BlockingQueue& repository);
};

#endif
