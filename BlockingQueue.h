#ifndef BLOCKING_QUEUE_H_
#define BLOCKING_QUEUE_H_

#include <map>
#include <mutex>
#include <iostream>
#include <vector>
#include <utility>
#include <condition_variable>
#include "./Material.h"
#include "./Worker.h"
#include "./Maybe.h"
#include "./BenefitPointRepository.h"

template<typename Entry, typename Processed>class Worker;

template<typename Entry, typename Processed>
class BlockingQueue {
    std::mutex notifierMutex;
    std::condition_variable sleepCondition;
    bool working = true;
    bool notified = false;

    public:
    BlockingQueue() {}

    void push(const Entry material) {
        std::unique_lock<std::mutex> lock(notifierMutex);
        _push(material);
        sleepCondition.notify_all();
        notified = true;
    }
    Maybe<Processed> pop(Worker<Entry, Processed>& worker) {
        std::unique_lock<std::mutex> lock(notifierMutex);

        while (!worker.continueCondition(*this)) {
            if (!working) {
                return Maybe<Processed>::nothing();
            }
            while (!notified) {
                sleepCondition.wait(lock);
                if (!working) return Maybe<BenefitPoints>::nothing();
            }
        }
        notified = false;
        std::vector<std::pair<Entry, size_t>> materials = 
            worker.requiredMaterials();
        std::vector<Entry> toProcess;
        _pop(materials, toProcess);
        BenefitPoints points = worker.processMaterials(toProcess);
        Maybe<BenefitPoints> toReturn(points);
        return toReturn;
    }

    void shutdown() {
        std::unique_lock<std::mutex> lock(notifierMutex);
        working = false;
        sleepCondition.notify_all();
    }

    protected:
    virtual void _pop(
        std::vector<std::pair<Entry, size_t>>& materials,
        std::vector<Entry>& toProcess);
    virtual void _push(const Entry material);
};

#endif