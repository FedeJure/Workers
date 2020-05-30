#include "./Main.h"

int main() {
    try
    {
        InventoryQueue inventory;
        BenefitPointRepository benefitPoints;


        MaterialQueue farmerQueue;
        MaterialQueue woodcutterQueue;
        MaterialQueue minerQueue;

        ResourcesProcessor processor(farmerQueue,
                                    woodcutterQueue,
                                    minerQueue);

        GatherersSpawner spawner(inventory,
                                farmerQueue,
                                woodcutterQueue,
                                minerQueue,
                                benefitPoints,
                                inventory);
        
        
        WorkersFactory factory(spawner);
        processor.waitUntilFinish();
        spawner.waitUntilFinish();

        benefitPoints.printPoints();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}