#include "./GatherersSpawner.h"
#include "Worker.h"

void GatherersSpawner::spawnWorkers(int farmers, int woodcutter, int miner,
                                    int chef, int carpenter, int weaponsmith) {
    spawnWorker(farmers, *this->FarmerQueue);
    spawnWorker(woodcutter, *this->WoodcutterQueue);
    spawnWorker(miner, *this->MinerQueue);
}

void GatherersSpawner::spawnWorker(int count, BlockingQueue<Material>& queue) {
    for (int i = 0; i < count; i++)
    {
        Worker* newWorker = new Worker(queue, *this->inventory);
        workers.push_back(newWorker);
    }
}

GatherersSpawner::~GatherersSpawner() {
    for (Worker* w : workers) {
        delete w;
    }   
}

void GatherersSpawner::waitUntilFinish() {
    for (Worker* w : workers) {
        w->waitUntilTerminate();
    }
}