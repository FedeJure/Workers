#include "./GatherersSpawner.h"
#include "Worker.h"

void GatherersSpawner::spawnWorkers(int farmers, int woodcutter, int miner,
                                    int chef, int carpenter, int weaponsmith) {
    spawnWorker(farmers, *this->FarmerQueue);
    spawnWorker(woodcutter, *this->WoodcutterQueue);
    spawnWorker(miner, *this->MinerQueue);
}

void GatherersSpawner::spawnWorker(int count, BlockingQueue<Material, Material>& queue) {
    for (int i = 0; i < count; i++)
    {
        Gatherer* newWorker = new Gatherer(queue, *this->inventory);
        workers.push_back(newWorker);
    }
}

// void GatherersSpawner::spawnWorker(int count, BlockingQueue<Material, BenefitPoints>& queue) {
//     for (int i = 0; i < count; i++)
//     {
//         Gatherer* newWorker = new Gatherer(queue, *this->inventory);
//         workers.push_back(newWorker);
//     }
// }

GatherersSpawner::~GatherersSpawner() {
    for (Gatherer* w : workers) {
        delete w;
    }   
}

void GatherersSpawner::waitUntilFinish() {
    for (Gatherer* w : workers) {
        w->waitUntilTerminate();
    }
}