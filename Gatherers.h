#include "./Works/BlockingQueue.h"
#include "./Worker/Worker.h"
#include "./Inventory.h"
#include <vector>

class Gatherers {
    BlockingQueue<int>* WheatQueue;
    BlockingQueue<int>* WoodQueue;
    BlockingQueue<int>* IronQueue;
    BlockingQueue<int>* CoalQueue;
    Inventory* inventory;
    std::vector<Worker*> workers;

    public:
    Gatherers(Inventory& inventory,
            BlockingQueue<int> &WheatQueue,
            BlockingQueue<int>& WoodQueue,
            BlockingQueue<int>& IronQueue,
            BlockingQueue<int>& CoalQueue){
                this->WheatQueue = &WheatQueue;
                this->WoodQueue = &WoodQueue;
                this->IronQueue = &IronQueue;
                this->CoalQueue = &CoalQueue;
                this->inventory = &inventory;
            }
    ~Gatherers();

    void spawnWorkers(int farmers, int woodcutter, int miner);
    void waitUntilFinish();

    private:
    void spawnWorker(int count, BlockingQueue<int>& queue);
};