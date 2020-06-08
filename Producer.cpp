#include <vector>
#include <utility>
#include "./Producer.h"

Producer::Producer(BlockingQueue& providedQueue,
                BenefitPointRepository& repository) {
    this->repository = &repository;
    this->inventory = &providedQueue;
    start();
}

Producer::~Producer() {}

void Producer::work() {
    bool working = true;
    std::vector<QueueRequestDto> materials = requiredMaterials();
    while (working) {
        std::vector<Material> value = this->inventory->pop(materials);
        if (!value.empty()) {
            std::chrono::milliseconds work_time(60);
            std::this_thread::sleep_for(work_time);
            this->repository->add(processMaterials(value));
        } else {
            working = false;
        }
    }
}
