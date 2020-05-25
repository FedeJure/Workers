#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <map>
#include <mutex>
#include <iostream>
#include "./Material.h"
#include "./BlockingQueue.h"


enum BenefitPoint {
    ChefPoint = 5,
    CarpenterPoint = 2,
    WeaponSmith = 3
};

// class Inventory {
//     std::map<Material, int> container;
//     std::mutex m;
//     public:

//     Inventory() {
//         container[Wheat] = 0;
//         container[Wood] = 0;
//         container[Iron] = 0;
//         container[Coal] = 0;
//     }

//     void add(Material material);
//     int count(Material type) const;
//     int remove(Material type, int count);
// };

class Inventory: public BlockingQueue<int>/*TODO:puntos de beneficio*/ {
    std::queue<Material> wheatQueue;
    std::queue<Material> woodQueue;
    std::queue<Material> ironQueue;
    std::queue<Material> coalQueue;
    std::map<Material, std::queue<Material>*> mapper;


    public:
    Inventory() {
        mapper[Wheat] = &wheatQueue;
        mapper[Wood] = &woodQueue;
        mapper[Iron] = &ironQueue;
        mapper[Coal] = &coalQueue;
    }

    void push(Material material) {
        std::unique_lock<std::mutex> lock(notifierMutex);
        mapper[material]->push(material);
    }
    void add(Material material);
    int count(Material type) const;
    int remove(Material type, int count);
};

#endif