#ifndef WORKER_H_
#define WORKER_H_
#include <thread>
#include "./Inventory.h"
#include "./Maybe.h"
#include "./Material.h"
#include "./BlockingQueue.h"

template<typename T, typename U>
class Worker {
    protected:
    std::thread thread;
    BlockingQueue<T, U>* queue;

    public:
    Worker(BlockingQueue<T, U>& providedQueue) :
        thread(&Worker<T, U>::work, this), queue(&providedQueue) {}
    void work() {
        std::cout << "Working!! \n";
        fflush(stdout);
        while(1) {
            Maybe<U> value = this->queue->pop();
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
    virtual void saveWork(U value) = 0;
};

#endif