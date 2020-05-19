#include "./WheatQueue.h"

int WheatQueue::consume() {
    return provider.consume();
}

void WheatQueue::provide(int count) {
    provider.provide(count);
}