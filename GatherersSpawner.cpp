#include "./GatherersSpawner.h"

void GatherersSpawner::spawnWorkers(int farmers, int woodcutter, int miner,
                                    int chef, int carpenter, int weaponsmith) {
    spawnWorker(farmers, *this->FarmerQueue);
    spawnWorker(woodcutter, *this->WoodcutterQueue);
    spawnWorker(miner, *this->MinerQueue);
    spawnWorker(chef, *this->chefQueue);
    spawnWorker(carpenter, *this->carpenterQueue);
    spawnWorker(weaponsmith, *this->weaponsmithQueue);
}

void GatherersSpawner::spawnWorker(int count, BlockingQueue<Material, Material>& queue) {
    for (int i = 0; i < count; i++)
    {
        Gatherer* newWorker = new Gatherer(queue, *this->inventory);
        gatherers.push_back(newWorker);
    }
}

void GatherersSpawner::spawnWorker(int count, BlockingQueue<Material, BenefitPoints>& queue) {
    for (int i = 0; i < count; i++)
    {
        Producer* newWorker = new Producer(queue, *this->benefitPoints);
        producers.push_back(newWorker);
    }
}

GatherersSpawner::~GatherersSpawner() {
    for (Gatherer* w : gatherers) {
        delete w;
    }   
}

void GatherersSpawner::waitUntilFinish() {
    for (Gatherer* w : gatherers) {
        w->waitUntilTerminate();
    }
    for (Producer* w : producers) {
        w->waitUntilTerminate();
    }

    
}