#ifndef BLOCKING_QUEUE_H_
#define BLOCKING_QUEUE_H_
#include <vector>
#include "./Material.h"
#include "./QueueRequestDto.h"
class BlockingQueue {
    protected:
    virtual std::vector<Material> extractMaterialsToProcess(
            std::vector<QueueRequestDto>& requests) = 0;
    virtual bool hasEnoughMaterials(
         std::vector<QueueRequestDto>& materials) = 0;

    public:
    virtual void push(const Material material) = 0;
    virtual std::vector<Material> pop(
         std::vector<QueueRequestDto>& requiredMaterials) = 0;
    virtual void shutdown() = 0;
};

#endif
