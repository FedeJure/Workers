#include "./GatherersSpawner.h"

void GatherersSpawner::spawnWorkers(int farmers, int woodcutter, int miner,
                                    int chef, int carpenter, int weaponsmith) {
    spawnWorker(farmers, *FarmerQueue);
    spawnWorker(woodcutter, *WoodcutterQueue);
    spawnWorker(miner, *MinerQueue);
    spawnProducer<Chef>(chef, *producersQueue, *benefitPoints, producers);
    spawnProducer<Carpenter>(carpenter, *producersQueue, *benefitPoints, producers);
    spawnProducer<Weaponsmith>(weaponsmith, *producersQueue, *benefitPoints, producers);
}

void GatherersSpawner::spawnWorker(int count, MaterialQueue& queue) {
    for (int i = 0; i < count; i++)
    {
        Gatherer* newWorker = new Gatherer(queue, *this->producersQueue);
        gatherers.push_back(std::move(newWorker));
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