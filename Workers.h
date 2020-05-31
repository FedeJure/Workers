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
    GatherersSpawner gatherersSpawner;
    ResourcesProcessor resourcesProcessor;
    WorkersFactory workersFactory;

    public:
    Workers(std::string& mapFileName, std::string& workersFileName) :
        gatherersSpawner(&farmerQueue,
                        &woodcutterQueue,
                        &minerQueue,
                        &benefitRepository,
                        &inventoryQueue),
        resourcesProcessor(&farmerQueue,
                        &woodcutterQueue,
                        &minerQueue,
                        mapFileName),
        workersFactory(&gatherersSpawner, workersFileName) {}

    ~Workers() {
        gatherersSpawner.waitUntilFinish();

        inventoryQueue.printRemainingMaterials();
        benefitRepository.printPoints();
    }
};

#endif
