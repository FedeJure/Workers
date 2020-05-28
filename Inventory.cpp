#include "./Inventory.h"

void Inventory::add(Material material) {
    std::cout << material;
    fflush(stdout);
    std::unique_lock<std::mutex> lock(m);
    int previousCount = container[material];
    container[material] = ++previousCount;
    fflush(stdout);
}

int Inventory::remove(Material type) {
    std::unique_lock<std::mutex> lock(m);
    int count = container[type]; 
    container[type] = 0; 
    return count;
}

bool Inventory::extractMaterials(std::vector<std::pair<Material, int>> materials) {
    std::unique_lock<std::mutex> lock(m);
    for (std::pair<Material, int> toExtract : materials) {
        if (container[toExtract.first] < toExtract.second) {
            return false;
        }
    }

    for (std::pair<Material, int> toExtract : materials) {
        container[toExtract.first] -= toExtract.second;
    }
    return true;
}