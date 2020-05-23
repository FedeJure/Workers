#include <fstream>
#include <map>
#include <iostream>
#include "./BlockingQueue.h"
class ResourcesProcessor {
    std::string fileName = "mapa.txt";
    std::ifstream file;
    std::thread thread;
    BlockingQueue<int> *FarmerQueue;
    BlockingQueue<int> *WoodcutterQueue;
    BlockingQueue<int> *MinerQueue;

    void process();

    public:
    ResourcesProcessor(
        BlockingQueue<int> &FarmerQueue,
        BlockingQueue<int>& WoodcutterQueue,
        BlockingQueue<int>& MinerQueue
    ) : file(fileName), thread(&ResourcesProcessor::process, this) {
        this->FarmerQueue = &FarmerQueue;
        this->WoodcutterQueue = &WoodcutterQueue;
        this->MinerQueue = &MinerQueue;
    }

    void waitUntilFinish();
    void addInQueue(BlockingQueue<int>& queue);


    ~ResourcesProcessor() {
        file.close();
    }
};