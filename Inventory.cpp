#include "./Inventory.h"
#include <iostream>

void Inventory::add(InventoryObject type, int count) {
    std::unique_lock<std::mutex> lock(m);
    int previousCount = container[type];
    previousCount += count;
    container[type] = previousCount;
    fflush(stdout);
}

int Inventory::remove(InventoryObject type) {
    std::unique_lock<std::mutex> lock(m);
    int count = container[type]; 
    container[type] = 0; 
    return count;
}