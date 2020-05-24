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
        container[Wheat().toString()] = 0;
        container[Wood().toString()] = 0;
        container[Iron().toString()] = 0;
        container[Coal().toString()] = 0;
    }

    void add(Material& material);
    int remove(std::string type);
};

#endif