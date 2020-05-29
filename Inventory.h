#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <map>
#include <mutex>
#include <iostream>
#include <vector>
#include <utility>
#include "./Material.h"
#include "./Observer.h"
class Inventory {
    std::map<Material, int> container;
    std::mutex m;
    std::vector<Observer*> observers;

    void notifyObservers();
    public:

    Inventory() {
        container[Wheat] = 0;
        container[Wood] = 0;
        container[Iron] = 0;
        container[Coal] = 0;
    }

    void add(Material material);
    int remove(Material type);
    bool extractMaterials(std::vector<std::pair<Material, int>> materials);
    void addObserver(Observer& observer);
};

#endif