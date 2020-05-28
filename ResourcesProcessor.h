#include <fstream>
#include <map>
#include <iostream>
#include "./Material.h"
#include "./BlockingQueue.h"
class ResourcesProcessor {
    std::string fileName = "mapa.txt";
    std::ifstream file;
    std::thread thread;
    BlockingQueue<Material, Material> *FarmerQueue;
    BlockingQueue<Material, Material> *WoodcutterQueue;
    BlockingQueue<Material, Material> *MinerQueue;

    void process();

    public:
    ResourcesProcessor(
        BlockingQueue<Material, Material> &FarmerQueue,
        BlockingQueue<Material, Material>& WoodcutterQueue,
        BlockingQueue<Material, Material>& MinerQueue
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