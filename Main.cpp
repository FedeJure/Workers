#include "./Main.h"

int main() {
    // recursos
    InventoryQueue inventory;
    BenefitPointRepository benefitPoints;

    // colas bloqueantes
    MaterialQueue farmerQueue;
    MaterialQueue woodcutterQueue;
    MaterialQueue minerQueue;

    // empieza procesamiento, se empiezan a llenar las colas
    ResourcesProcessor processor(farmerQueue,
                                woodcutterQueue,
                                minerQueue);

    GatherersSpawner spawner(inventory,
                            farmerQueue,
                            woodcutterQueue,
                            minerQueue,
                            benefitPoints,
                            inventory);
    
    

    // los trabajadores empiezan a consumir
    WorkersFactory factory(spawner);
    spawner.waitUntilFinish();
    processor.waitUntilFinish();


    return 0;
}