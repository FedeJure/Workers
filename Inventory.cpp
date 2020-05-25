#include "./Inventory.h"

// void Inventory::add(Material material) {
//     std::cout << material;
//     fflush(stdout);
//     std::unique_lock<std::mutex> lock(m);
//     int previousCount = container[material];
//     container[material] = ++previousCount;
//     fflush(stdout);
// }

// int Inventory::remove(Material type, int count) {
//     std::unique_lock<std::mutex> lock(m);
//     int toReturn = container[type] >= count ? count : 0;
//     container[type] -= toReturn;
//     return toReturn;
// }

// int Inventory::count(Material type) const {
//     return container.at(type);
// }


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

    BenefitPoint pop() {

    }
};