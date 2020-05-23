#include "./ResourcesProcessor.h"

void ResourcesProcessor::process() {
    
    std::string line;
    while (getline(file, line)) {
        std::cout <<line;
        for (size_t i = 0; i < line.size(); i++)
        {
            char readed = line[i];
            switch (readed) {
            case 'T':
                addInQueue(*FarmerQueue);
                break;
            case 'M':
                addInQueue(*WoodcutterQueue);
                break;
            case 'H':
                addInQueue(*MinerQueue);
                break;
            case 'C':
                addInQueue(*MinerQueue);
                break;
            default:
                break;
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

void ResourcesProcessor::addInQueue(BlockingQueue<int>& queue) {
    queue.push(1);
}