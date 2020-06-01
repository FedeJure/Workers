#include "./WorkerSpawner.h"

void WorkerSpawner::spawnWorkers(int farmers, int woodcutter, int miner,
                                    int chef, int carpenter, int weaponsmith) {
    spawnWorker(farmers, *FarmerQueue);
    spawnWorker(woodcutter, *WoodcutterQueue);
    spawnWorker(miner, *MinerQueue);
    spawnProducer<Chef>(chef, *producersQueue, *benefitPoints, producers);
    spawnProducer<Carpenter>
        (carpenter, *producersQueue, *benefitPoints, producers);
    spawnProducer<Weaponsmith>
        (weaponsmith, *producersQueue, *benefitPoints, producers);
}

void WorkerSpawner::spawnWorker(int count, MaterialQueue& queue) {
    for (int i = 0; i < count; i++)
    {
        gatherers.push_back(new Gatherer(queue, *this->producersQueue));
    }
}

WorkerSpawner::~WorkerSpawner() {
    for (Gatherer* g : gatherers) {
        delete g;
    }
    for (Producer* p : producers) {
        delete p;
    }
}

void WorkerSpawner::waitUntilFinish() {
    for (Gatherer* g : gatherers) {
        g->waitUntilTerminate();
    }
    producersQueue->shutdown();

    for (Producer* p : producers) {
        p->waitUntilTerminate();
    }
}
