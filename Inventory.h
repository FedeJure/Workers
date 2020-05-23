#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <map>
#include <mutex>

enum InventoryObject {
    WHEAT,
    WOOD,
    IRON,
    COAL
};

class Inventory {
    std::map<int, int> container;
    std::mutex m;
    public:

    Inventory() {
        container[WHEAT] = 0;
        container[WOOD] = 0;
        container[IRON] = 0;
        container[COAL] = 0;
    }

    void add(InventoryObject type, int count);
    int remove(InventoryObject type);
};

#endif