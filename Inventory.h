#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <map>
#include <mutex>
#include <iostream>
#include "./Material.h"

class Inventory {
    std::map<Material, int> container;
    std::mutex m;
    public:

    Inventory() {
        container[Wheat] = 0;
        container[Wood] = 0;
        container[Iron] = 0;
        container[Coal] = 0;
    }

    void add(Material material);
    int remove(Material type);
};

#endif