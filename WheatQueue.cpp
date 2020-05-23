#include "./WheatQueue.h"

Maybe<Wheat> WheatQueue::consume() {
    return provider.pop();
}

void WheatQueue::provide(Wheat wheat) {
    provider.push(wheat);
}

void WheatQueue::shutdown() {
    provider.shutdown();
}