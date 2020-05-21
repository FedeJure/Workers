#include "./WheatQueue.h"

Wheat WheatQueue::consume() {
    std::cout << "consume";
    return provider.pop();
}

void WheatQueue::provide(Wheat wheat) {
    std::cout << "provide";
    provider.push(wheat);
}