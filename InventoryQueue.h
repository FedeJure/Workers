#ifndef INVENTORY_QUEUE_H_
#define INVENTORY_QUEUE_H_
#include "./MaterialsQueue.h"
class InventoryQueue : public MaterialsQueue {
    public:
    InventoryQueue();
    void printRemainingMaterials();
};

#endif

