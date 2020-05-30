#ifndef RESOURCES_PROCESSOR_H
#define RESOURCES_PROCESSOR_H
#include <fstream>
#include <map>
#include <string>
#include <thread>
#include "./Material.h"
#include "./MaterialQueue.h"
class ResourcesProcessor {
    std::string fileName = "mapa.txt";
    std::ifstream file;
    std::thread thread;
    MaterialQueue *FarmerQueue;
    MaterialQueue *WoodcutterQueue;
    MaterialQueue *MinerQueue;

    void process();

    public:
    ResourcesProcessor(
        MaterialQueue& FarmerQueue,
        MaterialQueue& WoodcutterQueue,
        MaterialQueue& MinerQueue) 
        : file(fileName), thread(&ResourcesProcessor::process, this) {
        this->FarmerQueue = &FarmerQueue;
        this->WoodcutterQueue = &WoodcutterQueue;
        this->MinerQueue = &MinerQueue;
    }

    void waitUntilFinish();

    ~ResourcesProcessor() {
        file.close();
    }
};

#endif
