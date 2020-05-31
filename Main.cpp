#include <string>
#include "./Main.h"

int main(int argc, char *argv[]) {
    try
    {
        std::string mapFileName;
        std::string workersFileName;
        parseArguments(argc, argv, workersFileName, mapFileName);
        
        InventoryQueue inventory;
        BenefitPointRepository benefitPoints;


        MaterialQueue farmerQueue;
        MaterialQueue woodcutterQueue;
        MaterialQueue minerQueue;

        ResourcesProcessor processor(farmerQueue,
                                    woodcutterQueue,
                                    minerQueue,
                                    mapFileName);

        GatherersSpawner spawner(inventory,
                                farmerQueue,
                                woodcutterQueue,
                                minerQueue,
                                benefitPoints,
                                inventory);
        
        
        WorkersFactory factory(spawner, workersFileName);

        processor.waitUntilFinish();
        spawner.waitUntilFinish();

        inventory.printRemainingMaterials();
        benefitPoints.printPoints();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...) {
        std::cerr << "Unknown error.\n";
    }
    return 0;
}

void parseArguments(int argc, char *argv[],
    std::string& workersFile, std::string& map) {
    if (argc != 3) throw InvalidArgumentsError("Invalid args was passed.");
    std::string aux(argv[1]);
    workersFile = aux;
    std::string aux1(argv[2]);
    map = aux1;
}
