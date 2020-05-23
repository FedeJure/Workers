#include "./Gatherers.h"
#include "Worker/Worker.h"

void Gatherers::spawnWorkers(int farmers, int woodcutter, int miner) {
    spawnWorker(farmers, *this->WheatQueue);
    spawnWorker(woodcutter, *this->WoodQueue);
    spawnWorker(miner, *this->CoalQueue);
}

void Gatherers::spawnWorker(int count, BlockingQueue<int>& queue) {
    for (int i = 0; i < count; i++)
    {
        Worker* newWorker = new Worker(queue, *this->inventory);
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