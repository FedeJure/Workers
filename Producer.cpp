#include "./Producer.h"

void Producer::work() {
    while(1) {
        Maybe<BenefitPoints> value = this->inventory->pop(*this);
        if (value.hasValue()) { 

            std::chrono::milliseconds work_time(50);
            std::this_thread::sleep_for(work_time);
            this->repository->add(value.getValue());
        }
        else break;
    }
    fflush(stdout);
}

std::vector<std::pair<Material, size_t>> Chef::requiredMaterials() {
    return neededMaterials;
}
bool Chef::continueCondition(InventoryQueue& inventory) {
    bool condition = inventory.hasEnoughMaterials(neededMaterials);
    return condition;
}
BenefitPoints Chef::processMaterials(std::vector<Material>& materials) {
    return ChefPoint;
}

std::vector<std::pair<Material, size_t>> Carpenter::requiredMaterials() {
    return neededMaterials;
}
bool Carpenter::continueCondition(InventoryQueue& inventory) {
    bool condition = inventory.hasEnoughMaterials(neededMaterials);
    return condition;
}
BenefitPoints Carpenter::processMaterials(std::vector<Material>& materials) {
    return CarpenterPoint;
}

std::vector<std::pair<Material, size_t>> Weaponsmith::requiredMaterials() {
    return neededMaterials;
}
bool Weaponsmith::continueCondition(InventoryQueue& inventory) {
    bool condition = inventory.hasEnoughMaterials(neededMaterials);
    return condition;
}
BenefitPoints Weaponsmith::processMaterials(std::vector<Material>& materials) {
    return WeaponsmithPoints;
}