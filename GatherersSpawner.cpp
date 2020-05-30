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
        Gatherer* newWorker = new Gatherer(queue, *this->producersQueue);
        gatherers.push_back(std::move(newWorker));
    }
}

void GatherersSpawner::spawnWorker(int count, InventoryQueue& queue) {
    for (int i = 0; i < count; i++)
    {
        Producer* newWorker = new Chef(queue, *this->benefitPoints);
        producers.push_back(std::move(newWorker));
    }
}

GatherersSpawner::~GatherersSpawner() {
    for (Gatherer* g : gatherers) {
        delete g;
    }
    for (Producer* p : producers) {
        delete p;
    }
}

void GatherersSpawner::waitUntilFinish() {
    for (Worker* g : gatherers) {
        g->waitUntilTerminate();
    }
    producersQueue->shutdown();

    for (Producer* p : producers) {
        p->waitUntilTerminate();
    }

    
}