#include "./MaterialQueue.h"
#include <algorithm>

void MaterialQueue::push(const Material elem) {
    std::unique_lock<std::mutex> lock(notifierMutex);
    materials.push_back(elem);
    sleepCondition.notify_all();
    notified = true;
}

Maybe<Material> MaterialQueue::pop(Gatherer& worker) {
    std::unique_lock<std::mutex> lock(notifierMutex);
    while (this->materials.empty()) {
        if (!working) {
            return Maybe<Material>::nothing();
        }
        while (!notified) {
            sleepCondition.wait(lock);
        }
    }
    notified = false;
    Material aux = this->materials.back();
    this->materials.pop_back();
    Maybe<Material> toReturn(aux);
    return toReturn;
}

void MaterialQueue::shutdown() {
    std::unique_lock<std::mutex> lock(notifierMutex);
    working = false;
    sleepCondition.notify_all();
}
void MaterialQueue::_pop(
        std::vector<std::pair<Material, size_t>>& materials,
        std::vector<Material>& toProcess) {
    toProcess.pop_back();
}
void MaterialQueue::_push(const Material material) {
    materials.push_back(material);
}

size_t MaterialQueue::size() {
    return materials.size();
}