#ifndef GATHERERS_SPAWNER_H_
#define GATHERERS_SPAWNER_H_
#include <utility>
#include <vector>
#include "./MaterialQueue.h"
#include "./Gatherer.h"
#include "./Producer.h"
#include "./InventoryQueue.h"
#include "./BenefitPointRepository.h"

class WorkerSpawner {
    MaterialQueue* FarmerQueue;
    MaterialQueue* WoodcutterQueue;
    MaterialQueue* MinerQueue;
    InventoryQueue* producersQueue;
    BenefitPointRepository* benefitPoints;
    std::vector<Gatherer*> gatherers;
    std::vector<Producer*> producers;

    public:
    WorkerSpawner(MaterialQueue* FarmerQueue,
            MaterialQueue* WoodcutterQueue,
            MaterialQueue* MinerQueue,
            BenefitPointRepository* benefitPoints,
            InventoryQueue* producersQueue);
    ~WorkerSpawner();

    void spawnWorkers(int farmers, int woodcutter, int miner,
                        int chef, int carpenter, int weaponsmith);
    void waitUntilFinish();

    private:
    void spawnWorker(int count, MaterialQueue& queue);

    template<typename T>
    void spawnProducer(int count, InventoryQueue& source,
                        BenefitPointRepository& deposit,
                        std::vector<Producer*>& contenedor) {
        for (int i = 0; i < count; i++) {
            contenedor.push_back(new T(source, deposit));
        }
    }
};

#endif
