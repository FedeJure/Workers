#ifndef WORKERS_H_
#define WORKERS_H_
#include <string>
#include "./InventoryQueue.h"
#include "./FarmerQueue.h"
#include "./MinerQueue.h"
#include "./WoodcutterQueue.h"
#include "./WorkerSpawner.h"
#include "./ResourcesProcessor.h"
#include "./WorkersProcessor.h"

class Workers {
    InventoryQueue inventoryQueue;
    BenefitPointRepository benefitRepository;
    FarmerQueue farmerQueue;
    WoodcutterQueue woodcutterQueue;
    MinerQueue minerQueue;
    WorkerSpawner workerSpawner;
    ResourcesProcessor resourcesProcessor;
    WorkersFactory workersFactory;

    public:
    Workers(std::string& mapFileName, std::string& workersFileName);
    ~Workers();
};

#endif
