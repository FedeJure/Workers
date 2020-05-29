#ifndef GATHERERS_SPAWNER_H_
#define GATHERERS_SPAWNER_H_
#include "./MaterialQueue.h"
#include "./Gatherer.h"
#include "./Producer.h"
#include "./InventoryQueue.h"
#include "./ProducerQueue.h"
#include "./BenefitPointRepository.h"
#include <vector>

class GatherersSpawner {
    MaterialQueue* FarmerQueue;
    MaterialQueue* WoodcutterQueue;
    MaterialQueue* MinerQueue;
    InventoryQueue* producersQueue;
    BenefitPointRepository* benefitPoints;
    InventoryQueue* inventory;
    std::vector<Worker*> workers;

    public:
    GatherersSpawner(InventoryQueue& inventory,
            MaterialQueue& FarmerQueue,
            MaterialQueue& WoodcutterQueue,
            MaterialQueue& MinerQueue,
            BenefitPointRepository& benefitPoints,
            InventoryQueue& producersQueue){
                this->FarmerQueue = &FarmerQueue;
                this->WoodcutterQueue = &WoodcutterQueue;
                this->MinerQueue = &MinerQueue;
                this->inventory = &inventory;
                this->benefitPoints = &benefitPoints;
                this->producersQueue = &producersQueue;
            }
    ~GatherersSpawner();

    void spawnWorkers(int farmers, int woodcutter, int miner,
                        int chef, int carpenter, int weaponsmith);
    void waitUntilFinish();

    private:
    void spawnWorker(int count, MaterialQueue& queue);
    void spawnWorker(int count, InventoryQueue& queue);
};

#endif