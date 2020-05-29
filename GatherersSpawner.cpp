#include "./GatherersSpawner.h"

void GatherersSpawner::spawnWorkers(int farmers, int woodcutter, int miner,
                                    int chef, int carpenter, int weaponsmith) {
    spawnWorker(farmers, *this->FarmerQueue);
    spawnWorker(woodcutter, *this->WoodcutterQueue);
    spawnWorker(miner, *this->MinerQueue);
    spawnWorker(chef, *this->producersQueue);
    spawnWorker(carpenter, *this->producersQueue);
    spawnWorker(weaponsmith, *this->producersQueue);
}

void GatherersSpawner::spawnWorker(int count, MaterialQueue& queue) {
    for (int i = 0; i < count; i++)
    {
        Gatherer* newWorker = new Gatherer(queue, *this->inventory);
        workers.push_back(newWorker);
    }
}

void GatherersSpawner::spawnWorker(int count, InventoryQueue& queue) {
    for (int i = 0; i < count; i++)
    {
        Producer* newWorker = new Producer(queue, *this->benefitPoints);
        workers.push_back(newWorker);
    }
}

GatherersSpawner::~GatherersSpawner() {
    for (Worker* w : workers) {
        delete w;
    }   
}

void GatherersSpawner::waitUntilFinish() {
    for (Worker* w : workers) {
        w->waitUntilTerminate();
    }

    
}