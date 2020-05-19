#include "./WorkProvider.h"

int WorkProvider::consume() {
    int toReturn = 0;
    m.lock();
    toReturn = count;
    count = 0;
    m.unlock();
    return toReturn;
}

void WorkProvider::provide(int count) {
    m.lock();
    this->count += count;
    m.unlock();
}