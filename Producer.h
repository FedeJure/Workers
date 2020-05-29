#ifndef PRODUCER_H_
#define PRODUCER_H_
#include "./Worker.h"
#include "./BlockingQueue.h"
#include "./Inventory.h"
#include "./Material.h"
#include "./BenefitPointRepository.h"

// template<>
// Worker<Material, BenefitPoints>;
// class Producer: public Worker<Material, BenefitPoints> {
//     BenefitPointRepository* repository;
//     public:
//     Producer(BlockingQueue<Material, BenefitPoints>& providedQueue,
//             BenefitPointRepository& repository) : Worker<Material, BenefitPoints>(providedQueue) {
//         this->repository = &repository;
//     }
    
//     virtual ~Producer() {

//     }
//     protected:
//     virtual void saveWork(BenefitPoints values);
// };

class Producer {
    std::thread thread;
    BlockingQueue<Material, BenefitPoints>* queue;
    BenefitPointRepository* repository;

    

    public:
    Producer(BlockingQueue<Material, BenefitPoints>& providedQueue,
            BenefitPointRepository& repository) :
        thread(&Producer::work, this){
            this->repository = &repository;
            this->queue = &providedQueue;
        }
    void work();

    void waitUntilTerminate() {
        this->thread.join();
    }
    void saveWork(BenefitPoints value);
    bool wakeupCondition();
    void makeJob();
};


#endif