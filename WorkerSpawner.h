#ifndef GATHERERS_SPAWNER_H_
#define GATHERERS_SPAWNER_H_
#include <vector>
#include "./Producer.h"
#include "./BlockingQueue.h"
#include "./BenefitPointRepository.h"

class WorkerSpawner {
    BlockingQueue* FarmerQueue;
    BlockingQueue* WoodcutterQueue;
    BlockingQueue* MinerQueue;
    BlockingQueue* producersQueue;
    BenefitPointRepository* benefitPoints;
    std::vector<Worker*> gatherers;
    std::vector<Worker*> producers;

    public:
    WorkerSpawner(BlockingQueue* FarmerQueue,
            BlockingQueue* WoodcutterQueue,
            BlockingQueue* MinerQueue,
            BenefitPointRepository* benefitPoints,
            BlockingQueue* producersQueue);
    ~WorkerSpawner();

    void spawnWorkers(int farmers, int woodcutter, int miner,
                        int chef, int carpenter, int weaponsmith);
    void waitUntilFinish();

    private:
    template<typename T>
    void spawnProducer(int count, BlockingQueue& source,
                        BenefitPointRepository& deposit,
                        std::vector<Worker*>& contenedor) {
        for (int i = 0; i < count; i++) {
            contenedor.push_back(new T(source, deposit));
        }
    }
    template<typename T>
    void spawnGatherer(int count, BlockingQueue& source,
                        BlockingQueue& producersQueue,
                        std::vector<Worker*>& contenedor) {
        for (int i = 0; i < count; i++) {
            contenedor.push_back(new T(source, producersQueue));
        }
    }
};

#endif
