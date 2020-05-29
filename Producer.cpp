#include "./Producer.h"

void Producer::work() {
    std::cout << "Working!! Producer\n";
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

std::vector<std::pair<Material, int>> Chef::requiredMaterials() {
    std::vector<std::pair<Material, int>> required;
    return required;
}
bool Chef::continueCondition(const InventoryQueue& inventory) {
    return true;
}
BenefitPoints Chef::processMaterials(std::vector<Material>& materials) {
    return ChefPoint;
}