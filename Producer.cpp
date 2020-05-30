#include "./Producer.h"

void Producer::work() {
    fflush(stdout);
    while(1) {
        Maybe<BenefitPoints> value = this->inventory->pop(*this);
        if (value.hasValue()) { 
            std::chrono::milliseconds work_time(50);
            std::this_thread::sleep_for(work_time);
            this->repository->add(value.getValue());
        }
        else break;
    }
    std::cout << "stop working producer\n";
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