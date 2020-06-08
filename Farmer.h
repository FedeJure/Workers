#ifndef FARMER_H_
#define FARMER_H_
#include <vector>
#include "./Gatherer.h"
#include "./BlockingQueue.h"

class Farmer: public Gatherer {
    protected:
    virtual std::vector<QueueRequestDto> requiredMaterials();
    
    public:
    Farmer(BlockingQueue& providedQueue, BlockingQueue& repository);
};

#endif
