#include "./Main.h"

int main() {
    // recursos
    Inventory inventory;
    BenefitPointRepository benefitPoints;

    // colas bloqueantes
    BlockingQueue<Material, Material> farmerQueue;
    BlockingQueue<Material, Material> woodcutterQueue;
    BlockingQueue<Material, Material> minerQueue;
    ChefQueue chefQueue(inventory);
    CarpenterQueue carpenterQueue(inventory);
    WheaponsmithQueue weaponsmithQueue(inventory);

    // empieza procesamiento, se empiezan a llenar las colas
    ResourcesProcessor processor(farmerQueue,
                                woodcutterQueue,
                                minerQueue);

    GatherersSpawner spawner(inventory,
                            farmerQueue,
                            woodcutterQueue,
                            minerQueue,
                            benefitPoints,
                            chefQueue,
                            carpenterQueue,
                            weaponsmithQueue);
    
    

    // los trabajadores empiezan a consumir
    WorkersFactory factory(spawner);
    
    spawner.waitUntilFinish();
    processor.waitUntilFinish();


    return 0;
}