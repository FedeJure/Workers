#ifndef WORKERS_H_
#define WORKERS_H_
#include <string>
#include "./InventoryQueue.h"
#include "./MaterialQueue.h"
#include "./GatherersSpawner.h"
#include "./ResourcesProcessor.h"
#include "./WorkersFactory.h"

class Workers {
    InventoryQueue inventoryQueue;
    BenefitPointRepository benefitRepository;
    MaterialQueue farmerQueue;
    MaterialQueue woodcutterQueue;
    MaterialQueue minerQueue;
    ResourcesProcessor resourcesProcessor;
    GatherersSpawner gatherersSpawner;
    WorkersFactory workersFactory;

    public:
    Workers(std::string& mapFileName, std::string& workersFileName) :
        resourcesProcessor(&farmerQueue,
                        &woodcutterQueue,
                        &minerQueue,
                        mapFileName),
        gatherersSpawner(&farmerQueue,
                        &woodcutterQueue,
                        &minerQueue,
                        &benefitRepository,
                        &inventoryQueue),
        workersFactory(&gatherersSpawner, workersFileName) {
    }

    ~Workers() {
        resourcesProcessor.waitUntilFinish();
        gatherersSpawner.waitUntilFinish();

        inventoryQueue.printRemainingMaterials();
        benefitRepository.printPoints();
    }
};

#endif