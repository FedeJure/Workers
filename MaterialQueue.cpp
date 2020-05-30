#include "./MaterialQueue.h"

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
