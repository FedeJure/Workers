#include <string>
#include "./Workers.h"
Workers::Workers(std::string& mapFileName, std::string& workersFileName) :
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

Workers::~Workers() {
    workerSpawner.waitUntilFinish();

    inventoryQueue.printRemainingMaterials();
    benefitRepository.printPoints();
}
