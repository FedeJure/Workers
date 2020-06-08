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

void WorkerSpawner::spawnWorkers(uint32_t farmers, uint32_t woodcutter,
                                uint32_t miner, uint32_t chef,
                                uint32_t carpenter, uint32_t weaponsmith) {
    for (uint32_t i = 0; i < farmers; i++) {
        gatherers.push_back(new Farmer(*FarmerQueue, *producersQueue));
    }
    for (uint32_t i = 0; i < woodcutter; i++) {
        gatherers.push_back(new Woodcutter(*WoodcutterQueue, *producersQueue));
    }
    for (uint32_t i = 0; i < miner; i++) {
        gatherers.push_back(new Miner(*MinerQueue, *producersQueue));
    }
    for (uint32_t i = 0; i < chef; i++) {
        producers.push_back(new Chef(*producersQueue, *benefitPoints));
    }
    for (uint32_t i = 0; i < carpenter; i++) {
        producers.push_back(new Carpenter(*producersQueue, *benefitPoints));
    }
    for (uint32_t i = 0; i < weaponsmith; i++) {
        producers.push_back(new Weaponsmith(*producersQueue, *benefitPoints));
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
