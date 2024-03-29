#ifndef MATERIAL_QUEUE_H_
#define MATERIAL_QUEUE_H_
#include <vector>
#include <mutex>
#include <algorithm>
#include <condition_variable>
#include "./Maybe.h"
#include "./Gatherer.h"
#include "./Material.h"

class Gatherer;
class MaterialQueue {
    private:
    std::vector<Material> materials;
    std::mutex notifierMutex;
    std::condition_variable sleepCondition;
    bool working = true;
    bool notified = false;

    public:
    MaterialQueue();
    void push(const Material elem);
    Maybe<Material> pop(Gatherer& worker);
    void shutdown();
};

#endif
