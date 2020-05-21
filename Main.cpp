#include "./Works/WheatQueue.h"
#include "./Worker/Farmer.h"

int main() {
    // leer trabajadores
    // inicializar trabajadores , en threads
    // leer recursos
    
    // inicializar recursos en colas bloqueantes
    WheatQueue wheatQueue;

    // inicializar inventario
    // inicializar puntos de beneficio
    // inicir trabajadores
    Worker farmer(wheatQueue);

    Wheat w1(0);
    Wheat w2(1);
    wheatQueue.provide(w1);
    wheatQueue.provide(w2);

    farmer.startWorking();

    // imprimir resultado al finalizar 
    return 0;
}