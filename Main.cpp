#include <mutex>
#include "./Works/WheatQueue.h"
#include "./Gatherers.h"

int main() {
    // leer trabajadores
    // inicializar trabajadores , en threads
    // leer recursos
    
    
    // inicializar recursos en colas bloqueantes
    std::mutex sharedMutex;
    BlockingQueue<int> wheatQueue;
    BlockingQueue<int> woolQueue;
    BlockingQueue<int> ironQueue;
    BlockingQueue<int> coalQueue;

    // inicializar inventario
    // inicializar puntos de beneficio
    // inicir trabajadores
    Wheat w1(0);
    Wheat w2(1);
    Wheat w3(2);
    Wheat w4(3);
    Wheat w5(4);
    Wheat w6(5);
    Wheat w7(6);
    wheatQueue.push(w1);
    wheatQueue.push(w2);
    wheatQueue.push(w3);
    wheatQueue.push(w4);
    wheatQueue.push(w5);
    wheatQueue.push(w6);
    wheatQueue.push(w7);
    wheatQueue.shutdown();

    Gatherers gatherers(wheatQueue, woolQueue, ironQueue, coalQueue);
    gatherers.spawnFarmer(4);
    gatherers.waitUntilFinish();

    // imprimir resultado al finalizar 
    return 0;
}

void initResources() {

}