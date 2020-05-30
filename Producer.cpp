#include "./Producer.h"

void Producer::work() {
    while(1) {
        Maybe<BenefitPoints> value = this->inventory->pop(*this);
        if (value.hasValue()) { 

            std::chrono::milliseconds work_time(60);
            std::this_thread::sleep_for(work_time);
            this->repository->add(value.getValue());
        }
        else break;
    }
    fflush(stdout);
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