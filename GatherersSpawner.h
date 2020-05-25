#ifndef GATHERERS_SPAWNER_H_
#define GATHERERS_SPAWNER_H_
#include "./BlockingQueue.h"
#include "./Worker.h"
#include "./Inventory.h"
#include <vector>

class GatherersSpawner {
    BlockingQueue<Material>* FarmerQueue;
    BlockingQueue<Material>* WoodcutterQueue;
    BlockingQueue<Material>* MinerQueue;
    Inventory* inventory;
    std::vector<Worker*> workers;

    public:
    GatherersSpawner(Inventory& inventory,
            BlockingQueue<Material> &FarmerQueue,
            BlockingQueue<Material>& WoodcutterQueue,
            BlockingQueue<Material>& MinerQueue){
                this->FarmerQueue = &FarmerQueue;
                this->WoodcutterQueue = &WoodcutterQueue;
                this->MinerQueue = &MinerQueue;
                this->inventory = &inventory;
            }
    ~GatherersSpawner();

    void spawnWorkers(int farmers, int woodcutter, int miner,
                        int chef, int carpenter, int weaponsmith);
    void waitUntilFinish();

    private:
    void spawnWorker(int count, BlockingQueue<Material>& queue);
};

#endif