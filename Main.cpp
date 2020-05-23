#include "./Main.h"

int main() {
    // leer trabajadores
    // inicializar trabajadores , en threads
    // leer recursos
    
    
    // inicializar recursos en colas bloqueantes
    Inventory inventory;
    BlockingQueue<int> farmerQueue;
    BlockingQueue<int> woodcutterQueue;
    BlockingQueue<int> minerQueue;

    // inicializar inventario
    // inicializar puntos de beneficio
    // inicir trabajadores
    ResourcesProcessor processor(farmerQueue, woodcutterQueue, minerQueue);

    Gatherers gatherers(inventory, farmerQueue, woodcutterQueue, minerQueue);
    gatherers.spawnWorkers(4, 4, 4);
    gatherers.waitUntilFinish();
    processor.waitUntilFinish();

    return 0;
}