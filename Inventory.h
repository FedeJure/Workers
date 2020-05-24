#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <map>
#include <mutex>
#include <iostream>
#include "./Material.h"

class Inventory {
    std::map<std::string, int> container;
    std::mutex m;
    public:

    Inventory() {
        container[Wheat().type] = 0;
        container[Wood().type] = 0;
        container[Iron().type] = 0;
        container[Coal().type] = 0;
    }

    void add(Material material);
    int remove(std::string type);
};

#endif