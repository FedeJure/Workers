#include "./Main.h"

int main() {
    Inventory inventory;
    BlockingQueue<Material> farmerQueue;
    BlockingQueue<Material> woodcutterQueue;
    BlockingQueue<Material> minerQueue;

    ResourcesProcessor processor(farmerQueue, woodcutterQueue, minerQueue);
    GatherersSpawner spawner(inventory, farmerQueue, woodcutterQueue, minerQueue);
    WorkersFactory factory(spawner);

    factory.createWorkersFromFile();
    
    spawner.waitUntilFinish();
    processor.waitUntilFinish();

    return 0;
}