#include <string>
#include <fstream>
#include <map>
#include "./ResourcesProcessor.h"

ResourcesProcessor::ResourcesProcessor(
        BlockingQueue* FarmerQueue,
        BlockingQueue* WoodcutterQueue,
        BlockingQueue* MinerQueue,
        std::string& fileName) 
    : file(fileName) {
    this->farmerQueue = FarmerQueue;
    this->woodcutterQueue = WoodcutterQueue;
    this->minerQueue = MinerQueue;
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
                farmerQueue->push(Wheat);
            }
            if (readed == 'M') {
                woodcutterQueue->push(Wood);
            }
            if (readed == 'H') {
                minerQueue->push(Iron);
            }
            if (readed == 'C') {
                minerQueue->push(Coal);
            }
        }
    }
    farmerQueue->shutdown();
    minerQueue->shutdown();
    woodcutterQueue->shutdown();
    file.close();
}
