#include "./ResourcesProcessor.h"

void ResourcesProcessor::process() {
    
    std::string line;
    while (getline(file, line)) {
        for (size_t i = 0; i < line.size(); i++)
        {
            char readed = line[i];
            if (readed == 'T') {
                Wheat w;
                FarmerQueue->push(w);
            }
            if (readed == 'M') {
                Wood w;
                WoodcutterQueue->push(w);
            }
            if (readed == 'H'){
                Iron i;
                MinerQueue->push(i);
            }
            if (readed == 'C') {
                Coal c;
                MinerQueue->push(c);
            }
        }
    }
    FarmerQueue->shutdown();
    MinerQueue->shutdown();
    WoodcutterQueue->shutdown();
    
}

void ResourcesProcessor::waitUntilFinish() {
    thread.join();
}