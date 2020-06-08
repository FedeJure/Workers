#ifndef SINGLE_MATERIAL_QUEUE_H_
#define SINGLE_MATERIAL_QUEUE_H_
#include "./MaterialsQueue.h"
class SingleMaterialQueue : public MaterialsQueue {
    protected:
    virtual bool hasEnoughMaterials(
        std::vector<QueueRequestDto>& materials) override;

    public:
    SingleMaterialQueue();
};

#endif