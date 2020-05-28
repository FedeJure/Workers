#include "./Main.h"

int main() {
    Inventory inventory;
    BlockingQueue<Material, Material> farmerQueue;
    BlockingQueue<Material, Material> woodcutterQueue;
    BlockingQueue<Material, Material> minerQueue;
    BenefitPointRepository benefitPoints;
    ChefQueue chefQueue(inventory);
    CarpenterQueue carpenterQueue(inventory);
    WheaponsmithQueue weaponsmithQueue(inventory);


    ResourcesProcessor processor(farmerQueue, woodcutterQueue, minerQueue);
    GatherersSpawner spawner(inventory,
                            farmerQueue,
                            woodcutterQueue,
                            minerQueue,
                            benefitPoints,
                            chefQueue,
                            carpenterQueue,
                            weaponsmithQueue);
    WorkersFactory factory(spawner);

    factory.createWorkersFromFile();
    
    spawner.waitUntilFinish();
    processor.waitUntilFinish();


    return 0;
}