#include "./Gatherers.h"
#include "Worker/Worker.h"

void Gatherers::spawnFarmer(int count) {
    spawnWorker(count, *this->WheatQueue);
}

void Gatherers::spawnWoodcutter(int count) {
    spawnWorker(count, *this->WoodQueue);
}

void Gatherers::spawnMiner(int count) {
}

void Gatherers::spawnWorker(int count, BlockingQueue<int>& queue) {
    for (int i = 0; i < count; i++)
    {
        Worker* newWorker = new Worker(queue);
        workers.push_back(newWorker);
    }
}

Gatherers::~Gatherers() {
    for (Worker* w : workers) {
        delete w;
    }   
}

void Gatherers::waitUntilFinish() {
    for (Worker* w : workers) {
        w->waitUntilTerminate();
    }
}