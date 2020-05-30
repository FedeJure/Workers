#ifndef MATERIAL_QUEUE_H_
#define MATERIAL_QUEUE_H_
#include <queue>
#include <mutex>
#include <condition_variable>
#include "./Maybe.h"
#include "./Gatherer.h"
#include "./Material.h"

class Gatherer;
class MaterialQueue {
    private:
    std::queue<Material> queue;
    std::mutex notifierMutex;
    std::condition_variable sleepCondition;
    bool working = true;
    bool notified = false;

    public:
    MaterialQueue(){}

    void push(const Material elem) {
        std::unique_lock<std::mutex> lock(notifierMutex);
        queue.push(elem);
        sleepCondition.notify_all();
        notified = true;
    }

    Maybe<Material> pop(Gatherer& worker) {
        std::unique_lock<std::mutex> lock(notifierMutex);
        while(this->queue.empty()) {
            if (!working) {
                return Maybe<Material>::nothing();
            }
            while(!notified) {
                sleepCondition.wait(lock);
            }
        }
        notified = false;
        Material aux = this->queue.front();
        this->queue.pop();
        Maybe<Material> toReturn(aux);
        return toReturn;
    }

    void shutdown() {
        std::unique_lock<std::mutex> lock(notifierMutex);
        working = false;
        sleepCondition.notify_all();
    }
};

#endif