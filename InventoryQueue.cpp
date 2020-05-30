#include "./InventoryQueue.h"

bool InventoryQueue::hasEnoughMaterials(std::vector<std::pair<Material, size_t>>& materials) {
    bool hasEnough = true;
    for (std::pair<Material, size_t> pair : materials) {
        if (this->container[pair.first].size() < pair.second) {
            hasEnough = false;
            fflush(stdout);
            break;
        }
    }
    return hasEnough;
}

Maybe<BenefitPoints> InventoryQueue::pop(Producer& worker) {
    std::unique_lock<std::mutex> lock(notifierMutex);
    while(!worker.continueCondition(*this)) {
        if (!working) {
            return Maybe<BenefitPoints>::nothing();
        }
        while(!notified) {
            fflush(stdout);
            sleepCondition.wait(lock);
        }
    }
    std::cout<<"pop\n";
    fflush(stdout);
    notified = false;
    std::vector<std::pair<Material, size_t>> materials = worker.requiredMaterials();
    std::vector<Material> toProcess;
    extractMaterialsToProcess(materials, toProcess);
    BenefitPoints points = worker.processMaterials(toProcess);
    Maybe<BenefitPoints> toReturn(points);
    return toReturn;
}


void InventoryQueue::push(const Material material) {
    std::unique_lock<std::mutex> lock(inventaryMutex);
    std::cout<<"push\n";
    fflush(stdout);
    container[material].push_back(material);
    sleepCondition.notify_all();
    notified = true;
}
void InventoryQueue::shutdown() {
    std::unique_lock<std::mutex> lock(inventaryMutex);
    std::cout<<"shutdown\n";
    fflush(stdout);
    working = false;
    sleepCondition.notify_all();
}

void InventoryQueue::extractMaterialsToProcess(
                std::vector<std::pair<Material, size_t>>& materials,
                std::vector<Material>& toProcess) {

    std::lock_guard<std::mutex> lock(inventaryMutex);
    std::cout<<"extractMATERIALS\n";
    fflush(stdout);
    for (std::pair<Material, size_t> par : materials) {
        while (par.second > 0)  {
            toProcess.push_back(container[par.first].back());
            container[par.first].pop_back();
            par.second--;
        }
    }
}


void InventoryQueue::printRemainingMaterials() {
    std::cout<<"Recursos restantes:\n";
    std::cout<<"  - Trigo: "<<container[Wheat].size()<<"\n";
    std::cout<<"  - Madera: "<<container[Wood].size()<<"\n";
    std::cout<<"  - Carbon: "<<container[Coal].size()<<"\n";
    std::cout<<"  - Hierro: "<<container[Iron].size()<<"\n";
}