#ifndef WORKERS_H_
#define WORKERS_H_
#include <string>
#include "./InventoryQueue.h"
#include "./MaterialQueue.h"
#include "./WorkerSpawner.h"
#include "./ResourcesProcessor.h"
#include "./WorkersFactory.h"

class Workers {
    InventoryQueue inventoryQueue;
    BenefitPointRepository benefitRepository;
    MaterialQueue farmerQueue;
    MaterialQueue woodcutterQueue;
    MaterialQueue minerQueue;
    WorkerSpawner workerSpawner;
    ResourcesProcessor resourcesProcessor;
    WorkersFactory workersFactory;

    public:
    Workers(std::string& mapFileName, std::string& workersFileName) :
        workerSpawner(&farmerQueue,
                        &woodcutterQueue,
                        &minerQueue,
                        &benefitRepository,
                        &inventoryQueue),
        resourcesProcessor(&farmerQueue,
                        &woodcutterQueue,
                        &minerQueue,
                        mapFileName),
        workersFactory(&workerSpawner, workersFileName) {}

    ~Workers() {
        workerSpawner.waitUntilFinish();

        inventoryQueue.printRemainingMaterials();
        benefitRepository.printPoints();
    }
};

#endif
