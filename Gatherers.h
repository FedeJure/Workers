#include "./Works/BlockingQueue.h"
#include "./Worker/Worker.h"
#include <vector>

class Gatherers {
    BlockingQueue<int>* WheatQueue;
    BlockingQueue<int>* WoodQueue;
    BlockingQueue<int>* IronQueue;
    BlockingQueue<int>* CoalQueue;
    std::vector<Worker*> workers;

    public:
    Gatherers(BlockingQueue<int> &WheatQueue,
            BlockingQueue<int>& WoodQueue,
            BlockingQueue<int>& IronQueue,
            BlockingQueue<int>& CoalQueue){
                this->WheatQueue = &WheatQueue;
                this->WoodQueue = &WoodQueue;
                this->IronQueue = &IronQueue;
                this->CoalQueue = &CoalQueue;
            }
    ~Gatherers();
    
    void spawnFarmer(int count);
    void spawnWoodcutter(int count);
    void spawnMiner(int count);
    void waitUntilFinish();

    private:
    void spawnWorker(int count, BlockingQueue<int>& queue);
};