#include "./Inventory.h"

void Inventory::add(Material& material) {
    std::cout << material.toString();
    fflush(stdout);
    std::unique_lock<std::mutex> lock(m);
    int previousCount = container[material.toString()];
    container[material.toString()] = ++previousCount;
    fflush(stdout);
}

int Inventory::remove(std::string type) {
    std::unique_lock<std::mutex> lock(m);
    int count = container[type]; 
    container[type] = 0; 
    return count;
}