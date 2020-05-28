#include "./BenefitPointRepository.h"

int BenefitPointRepository::get() {
    std::unique_lock<std::mutex> lock(m);
    return points;
}

void BenefitPointRepository::add(int value) {
    std::unique_lock<std::mutex> lock(m);
    points += value;
}