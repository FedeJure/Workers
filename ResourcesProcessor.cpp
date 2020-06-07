#include <string>
#include "./ResourcesProcessor.h"

ResourcesProcessor::ResourcesProcessor(
        MaterialQueue* FarmerQueue,
        MaterialQueue* WoodcutterQueue,
        MaterialQueue* MinerQueue,
        std::string& fileName) 
    : file(fileName) {
    this->FarmerQueue = FarmerQueue;
    this->WoodcutterQueue = WoodcutterQueue;
    this->MinerQueue = MinerQueue;
    process();
}

ResourcesProcessor::~ResourcesProcessor() {
    file.close();
}

void ResourcesProcessor::process() {
    std::string line;
    while (getline(file, line)) {
        for (uint32_t i = 0; i < line.size(); i++) {
            char readed = line[i];
            if (readed == 'T') {
                FarmerQueue->push(Wheat);
            }
            if (readed == 'M') {
                WoodcutterQueue->push(Wood);
            }
            if (readed == 'H') {
                MinerQueue->push(Iron);
            }
            if (readed == 'C') {
                MinerQueue->push(Coal);
            }
        }
    }
    FarmerQueue->shutdown();
    MinerQueue->shutdown();
    WoodcutterQueue->shutdown();
    file.close();
}
