#include "./ProducerQueue.h"


BenefitPoints ChefQueue::_pop() {
    BenefitPoints points = ChefPoint;
    return points;
}
bool ChefQueue::_continueCondition() {
    std::vector<std::pair<Material, int>> neededMaterials;
    neededMaterials.push_back(std::pair<Material, int>(Wheat, 2));
    neededMaterials.push_back(std::pair<Material, int>(Coal, 1));
    return this->inventory->extractMaterials(neededMaterials);
}


BenefitPoints WheaponsmithQueue::_pop() {
    BenefitPoints points = WeaponsmithPoints;
    return points;
}
bool WheaponsmithQueue::_continueCondition() {
    std::vector<std::pair<Material, int>> neededMaterials;
    neededMaterials.push_back(std::pair<Material, int>(Iron, 2));
    neededMaterials.push_back(std::pair<Material, int>(Coal, 2));
    return this->inventory->extractMaterials(neededMaterials);
}


BenefitPoints CarpenterQueue::_pop() {
    BenefitPoints points = ChefPoint;
    return points;
}
bool CarpenterQueue::_continueCondition() {
    std::vector<std::pair<Material, int>> neededMaterials;
    neededMaterials.push_back(std::pair<Material, int>(Wood, 3));
    neededMaterials.push_back(std::pair<Material, int>(Iron, 1));
    return this->inventory->extractMaterials(neededMaterials);
}