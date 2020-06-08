#ifndef GATHERERS_SPAWNER_H_
#define GATHERERS_SPAWNER_H_
#include <vector>
#include "./Producer.h"
#include "./Gatherer.h"
#include "./BlockingQueue.h"
#include "./BenefitPointRepository.h"

class WorkerSpawner {
    BlockingQueue* FarmerQueue;
    BlockingQueue* WoodcutterQueue;
    BlockingQueue* MinerQueue;
    BlockingQueue* producersQueue;
    BenefitPointRepository* benefitPoints;
    std::vector<Gatherer*> gatherers;
    std::vector<Producer*> producers;

    public:
    WorkerSpawner(BlockingQueue* FarmerQueue,
            BlockingQueue* WoodcutterQueue,
            BlockingQueue* MinerQueue,
            BenefitPointRepository* benefitPoints,
            BlockingQueue* producersQueue);
    ~WorkerSpawner();

    void spawnWorkers(uint32_t farmers, uint32_t woodcutter,
                        uint32_t miner, uint32_t chef,
                        uint32_t carpenter, uint32_t weaponsmith);
    void waitUntilFinish();
};

#endif
