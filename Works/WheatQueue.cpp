#include "./WheatQueue.h"

Wheat WheatQueue::consume() {
    return provider.pop();
}

void WheatQueue::provide(Wheat wheat) {
    provider.push(wheat);
}

bool WheatQueue::isEmpty() {
    return provider.isEmpty();
}

bool WheatQueue::isRunning() {
    return provider.isRunning();
}

void WheatQueue::shutdown() {
    provider.shutdown();
}