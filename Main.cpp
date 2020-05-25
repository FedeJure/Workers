#include "./Main.h"

int main() {
    Inventory inventory;
    BlockingQueue<Material> farmerQueue;
    BlockingQueue<Material> woodcutterQueue;
    BlockingQueue<Material> minerQueue;

    ResourcesProcessor processor(farmerQueue, woodcutterQueue, minerQueue);
    WorkersFactory factory(4,4,4);
    factory.createWorkersFromFile();
    Gatherers gatherers(inventory, farmerQueue, woodcutterQueue, minerQueue);

    gatherers.spawnWorkers(4, 4, 4);
    
    gatherers.waitUntilFinish();
    processor.waitUntilFinish();

    return 0;
}