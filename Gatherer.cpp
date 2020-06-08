#include <vector>
#include "./Gatherer.h"

Gatherer::Gatherer(BlockingQueue& providedQueue,
            BlockingQueue& inventory) {
    this->inventory = &inventory;
    this->queue = &providedQueue;
    start();
}

Gatherer::~Gatherer() {}

void Gatherer::work() {
    bool working = true;
    std::vector<QueueRequestDto> materials = requiredMaterials();
    while (working) {
        std::vector<Material> value = this->queue->pop(materials);
        if (!value.empty()) { 
            std::chrono::milliseconds work_time(50);
            std::this_thread::sleep_for(work_time);
            this->inventory->push(value[0]);
        } else {
            working = false;
        }
    }
}
