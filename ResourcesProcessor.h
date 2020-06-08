#ifndef RESOURCES_PROCESSOR_H
#define RESOURCES_PROCESSOR_H
#include <fstream>
#include <string>
#include "./Material.h"
#include "./BlockingQueue.h"

class ResourcesProcessor {
    std::ifstream file;
    BlockingQueue* farmerQueue;
    BlockingQueue* woodcutterQueue;
    BlockingQueue* minerQueue;
    void process();

    public:
    ResourcesProcessor(
        BlockingQueue* FarmerQueue,
        BlockingQueue* WoodcutterQueue,
        BlockingQueue* MinerQueue,
        std::string& fileName);
    ~ResourcesProcessor();
};

#endif
