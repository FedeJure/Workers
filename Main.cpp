#include <mutex>
#include "./Works/WheatQueue.h"
#include "./Gatherers.h"
#include "./Inventory.h"

int main() {
    // leer trabajadores
    // inicializar trabajadores , en threads
    // leer recursos
    
    
    // inicializar recursos en colas bloqueantes
    Inventory inventory;
    BlockingQueue<int> wheatQueue;
    BlockingQueue<int> woolQueue;
    BlockingQueue<int> ironQueue;
    BlockingQueue<int> coalQueue;

    // inicializar inventario
    // inicializar puntos de beneficio
    // inicir trabajadores
    wheatQueue.push(1);
    wheatQueue.push(1);
    wheatQueue.push(1);
    wheatQueue.push(1);
    wheatQueue.push(1);
    wheatQueue.push(1);
    wheatQueue.push(1);
    wheatQueue.shutdown();

    Gatherers gatherers(inventory, wheatQueue, woolQueue, ironQueue, coalQueue);
    gatherers.spawnWorkers(4, 0, 0);
    gatherers.waitUntilFinish();

    // imprimir resultado al finalizar 
    return 0;
}

void initResources() {

}