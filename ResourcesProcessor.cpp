#include "./ResourcesProcessor.h"

void ResourcesProcessor::process() {
    
    std::string line;
    while (getline(file, line)) {
        for (size_t i = 0; i < line.size(); i++)
        {
            char readed = line[i];
            if (readed == 'T') {
                FarmerQueue->push(Wheat);
            }
            if (readed == 'M') {
                WoodcutterQueue->push(Wood);
            }
            if (readed == 'H'){
                MinerQueue->push(Iron);
            }
            if (readed == 'C') {
                MinerQueue->push(Coal);
            }
        }
    }
    std::cout<<"\nFinish Process!!!\n";
    FarmerQueue->shutdown();
    MinerQueue->shutdown();
    WoodcutterQueue->shutdown();
    
}

void ResourcesProcessor::waitUntilFinish() {
    thread.join();
}