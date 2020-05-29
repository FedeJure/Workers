#include <fstream>
#include <map>
#include <iostream>
#include "./Material.h"
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
        MaterialQueue& MinerQueue
    ) : file(fileName), thread(&ResourcesProcessor::process, this) {
        this->FarmerQueue = &FarmerQueue;
        this->WoodcutterQueue = &WoodcutterQueue;
        this->MinerQueue = &MinerQueue;
    }

    void waitUntilFinish();

    ~ResourcesProcessor() {
        file.close();
    }
};