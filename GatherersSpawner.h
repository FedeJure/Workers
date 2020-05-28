#ifndef GATHERERS_SPAWNER_H_
#define GATHERERS_SPAWNER_H_
#include "./BlockingQueue.h"
#include "./Worker.h"
#include "./Inventory.h"
#include "./ProducerQueue.h"
#include "./BenefitPointRepository.h"
#include <vector>

class GatherersSpawner {
    BlockingQueue<Material, Material>* FarmerQueue;
    BlockingQueue<Material, Material>* WoodcutterQueue;
    BlockingQueue<Material, Material>* MinerQueue;
    ChefQueue* chefQueue;
    CarpenterQueue* carpenterQueue;
    WheaponsmithQueue* weaponsmithQueue;
    BenefitPointRepository* benefitPoints;
    Inventory* inventory;
    std::vector<Gatherer*> workers;

    public:
    GatherersSpawner(Inventory& inventory,
            BlockingQueue<Material, Material> &FarmerQueue,
            BlockingQueue<Material, Material>& WoodcutterQueue,
            BlockingQueue<Material, Material>& MinerQueue,
            BenefitPointRepository& benefitPoints,
            ChefQueue& chefQueue,
            CarpenterQueue& carpenterQueue,
            WheaponsmithQueue& weaponsmithQueue){
                this->FarmerQueue = &FarmerQueue;
                this->WoodcutterQueue = &WoodcutterQueue;
                this->MinerQueue = &MinerQueue;
                this->inventory = &inventory;
                this->benefitPoints = &benefitPoints;
                this->chefQueue = &chefQueue;
                this->carpenterQueue = &carpenterQueue;
                this->weaponsmithQueue = &weaponsmithQueue;
            }
    ~GatherersSpawner();

    void spawnWorkers(int farmers, int woodcutter, int miner,
                        int chef, int carpenter, int weaponsmith);
    void waitUntilFinish();

    private:
    void spawnWorker(int count, BlockingQueue<Material, Material>& queue);
};

#endif