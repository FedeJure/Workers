#ifndef WOODCUTTER_H_
#define WOODCUTTER_H_
#include <vector>
#include "./Gatherer.h"
#include "./BlockingQueue.h"

class Woodcutter: public Gatherer {
    protected:
    virtual std::vector<QueueRequestDto> requiredMaterials();
    
    public:
    Woodcutter(BlockingQueue& providedQueue, BlockingQueue& repository);
    ~Woodcutter();
};

#endif

