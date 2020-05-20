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
    Farmer farmer(wheatQueue);
    farmer.startWorking();
    // imprimir resultado al finalizar 
    return 0;
}