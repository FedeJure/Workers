#include "./WorkerSpawner.h"
#include "./Chef.h"
#include "./Carpenter.h"
#include "./Gatherer.h"
#include "./Farmer.h"
#include "./Woodcutter.h"
#include "./Miner.h"
#include "./Weaponsmith.h"

WorkerSpawner::WorkerSpawner(BlockingQueue* FarmerQueue,
            BlockingQueue* WoodcutterQueue,
            BlockingQueue* MinerQueue,
            BenefitPointRepository* benefitPoints,
            BlockingQueue* producersQueue) {
    this->FarmerQueue = FarmerQueue;
    this->WoodcutterQueue = WoodcutterQueue;
    this->MinerQueue = MinerQueue;
    this->benefitPoints = benefitPoints;
    this->producersQueue = producersQueue;
}

void WorkerSpawner::spawnWorkers(int farmers, int woodcutter, int miner,
                                    int chef, int carpenter, int weaponsmith) {
    spawnGatherer<Farmer>(farmers, *FarmerQueue, *producersQueue, gatherers);
    // spawnGatherer<Woodcutter>
    //     (woodcutter, *WoodcutterQueue, *producersQueue, gatherers);
    // spawnGatherer<Miner>(miner, *MinerQueue, *producersQueue, gatherers);
    // spawnProducer<Chef>(chef, *producersQueue, *benefitPoints, producers);
    // spawnProducer<Carpenter>
    //     (carpenter, *producersQueue, *benefitPoints, producers);
    // spawnProducer<Weaponsmith>
    //     (weaponsmith, *producersQueue, *benefitPoints, producers);
}

WorkerSpawner::~WorkerSpawner() {
    for (Worker* g : gatherers) {
        delete g;
    }
    for (Worker* p : producers) {
        delete p;
    }
}

void WorkerSpawner::waitUntilFinish() {
    for (Worker* g : gatherers) {
        g->waitUntilTerminate();
    }
    producersQueue->shutdown();

    for (Worker* p : producers) {
        p->waitUntilTerminate();
    }
}
