#include "./InventoryQueue.h"

InventoryQueue::InventoryQueue() {
    container[Wheat];
    container[Wood];
    container[Iron];
    container[Coal];
}

void InventoryQueue::printRemainingMaterials() {
    std::cout<<"Recursos restantes:\n";
    std::cout<<"  - Trigo: "<<container[Wheat].size()<<"\n";
    std::cout<<"  - Madera: "<<container[Wood].size()<<"\n";
    std::cout<<"  - Carbon: "<<container[Coal].size()<<"\n";
    std::cout<<"  - Hierro: "<<container[Iron].size()<<"\n\n";
    fflush(stdout);
}
