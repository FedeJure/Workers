#include "./BenefitPointRepository.h"

int BenefitPointRepository::get() {
    std::unique_lock<std::mutex> lock(m);
    return points;
}

void BenefitPointRepository::add(BenefitPoints value) {
    std::unique_lock<std::mutex> lock(m);
    points += value;
}