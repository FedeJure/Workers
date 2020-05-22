#include <mutex>
#include "./Works/WheatQueue.h"
#include "./Worker/Worker.h"

int main() {
    // leer trabajadores
    // inicializar trabajadores , en threads
    // leer recursos
    
    
    // inicializar recursos en colas bloqueantes
    std::mutex sharedMutex;
    WheatQueue wheatQueue;

    // inicializar inventario
    // inicializar puntos de beneficio
    // inicir trabajadores
    Worker farmer(wheatQueue);
    Worker farmer1(wheatQueue);

    Wheat w1(0);
    Wheat w2(1);
    Wheat w3(2);
    Wheat w4(3);
    Wheat w5(4);
    Wheat w6(5);
    Wheat w7(6);
    wheatQueue.provide(w1);
    wheatQueue.provide(w2);
    wheatQueue.provide(w3);
    wheatQueue.provide(w4);
    wheatQueue.provide(w5);
    wheatQueue.provide(w6);
    wheatQueue.provide(w7);
    wheatQueue.shutdown();
    
    farmer.waitUntilTerminate();
    farmer1.waitUntilTerminate();

    // imprimir resultado al finalizar 
    return 0;
}