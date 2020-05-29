#include "./InventoryQueue.h"


void InventoryQueue::push(const Material material) {
    std::unique_lock<std::mutex> lock(notifierMutex);
    container[material].push_back(material);
    sleepCondition.notify_all();
    notified = true;
}

Maybe<BenefitPoints> InventoryQueue::pop(Producer& worker) {
    std::unique_lock<std::mutex> lock(notifierMutex);
    while(worker.continueCondition(*this)) {
        if (!working) {
            return Maybe<BenefitPoints>::nothing();
        }
        while(!notified) {
            sleepCondition.wait(lock);
        }
    }
    notified = false;
    std::vector<std::pair<Material, int>> materials = worker.requiredMaterials();
    std::vector<Material> toProcess;
    extractMaterialsToProcess(materials, toProcess);
    BenefitPoints points = worker.processMaterials(toProcess);
    Maybe<BenefitPoints> toReturn(points);
    return toReturn;
}

void InventoryQueue::shutdown() {
    std::unique_lock<std::mutex> lock(notifierMutex);
    working = false;
    sleepCondition.notify_all();
}

void InventoryQueue::extractMaterialsToProcess(
                std::vector<std::pair<Material, int>>& materials,
                std::vector<Material>& toProcess) {

    for (std::pair<Material, int> par : materials) {
        while (par.second > 0)  {
            toProcess.push_back(container[par.first].back());
            container[par.first].pop_back();
            par.second--;
        }
    }
    
}