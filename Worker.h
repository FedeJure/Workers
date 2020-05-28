#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "./Inventory.h"
#include "./Maybe.h"
#include "./Material.h"
#include "./BlockingQueue.h"

template<typename U, typename T>
class Worker {
    protected:
    std::thread thread;
    BlockingQueue<U, T>* queue;

    public:
    Worker(BlockingQueue<U, T>& providedQueue) :
        thread(&Worker::work, this), queue(&providedQueue) {}
    void work() {
        std::cout << "Working!! \n";
        fflush(stdout);
        while(1) {
            Maybe<T> value = this->queue->pop();
            if (value.hasValue()) { 
                std::chrono::milliseconds work_time(50);
                std::this_thread::sleep_for(work_time);
                this->saveWork(value.getValue());
            }
            else break;
        }
        std::cout << "stop working\n";
        fflush(stdout);
    }

    void waitUntilTerminate() {
        this->thread.join();
    }

    protected:
    virtual void saveWork(T value) = 0;
};


class Gatherer: public Worker<Material, Material> {
    Inventory* inventory;
    public:
    Gatherer(BlockingQueue<Material, Material>& providedQueue,
            Inventory& inventory) : Worker<Material, Material>(providedQueue) {
        this->inventory = &inventory;
    }
    
    virtual ~Gatherer() {

    }
    protected:
    virtual void saveWork(Material values);
};
#endif