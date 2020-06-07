#include <vector>
#include <utility>
#include "./Producer.h"

Producer::Producer(InventoryQueue& providedQueue,
                BenefitPointRepository& repository,
                std::initializer_list<std::pair<Material, size_t>> materials,
                BenefitPoints points): 
        neededMaterials(materials), pointsOnProcess(points) {
    this->repository = &repository;
    this->inventory = &providedQueue;
    start();
}

Producer::~Producer() {}

void Producer::work() {
    bool working = true;
    while (working) {
        std::vector<std::pair<Material, size_t>> materials = 
            requiredMaterials();
        std::vector<Material> value = this->inventory->pop(materials);
        if (!value.empty()) {
            std::chrono::milliseconds work_time(60);
            std::this_thread::sleep_for(work_time);
            this->repository->add(processMaterials(value));
        } else {
            working = false;
        }
    }
}

std::vector<std::pair<Material, size_t>> Producer::requiredMaterials() {
    return neededMaterials;
}
bool Producer::continueCondition(InventoryQueue& inventory) {
    bool condition = inventory.hasEnoughMaterials(neededMaterials);
    return condition;
}
BenefitPoints Producer::processMaterials(std::vector<Material>& materials) {
    return pointsOnProcess;
}
