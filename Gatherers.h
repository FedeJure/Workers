#include "./BlockingQueue.h"
#include "./Worker.h"
#include "./Inventory.h"
#include <vector>

class Gatherers {
    BlockingQueue<Material>* FarmerQueue;
    BlockingQueue<Material>* WoodcutterQueue;
    BlockingQueue<Material>* MinerQueue;
    Inventory* inventory;
    std::vector<Worker*> workers;

    public:
    Gatherers(Inventory& inventory,
            BlockingQueue<Material> &FarmerQueue,
            BlockingQueue<Material>& WoodcutterQueue,
            BlockingQueue<Material>& MinerQueue){
                this->FarmerQueue = &FarmerQueue;
                this->WoodcutterQueue = &WoodcutterQueue;
                this->MinerQueue = &MinerQueue;
                this->inventory = &inventory;
            }
    ~Gatherers();

    void spawnWorkers(int farmers, int woodcutter, int miner);
    void waitUntilFinish();

    private:
    void spawnWorker(int count, BlockingQueue<Material>& queue);
};