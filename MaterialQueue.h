#ifndef MATERIAL_QUEUE_H_
#define MATERIAL_QUEUE_H_
#include <vector>
#include <mutex>
#include <algorithm>
#include <condition_variable>
#include "./BlockingQueue.h"
#include "./BenefitPointRepository.h"
#include "./Maybe.h"
#include "./Gatherer.h"
#include "./Material.h"

class Gatherer;
class MaterialQueue: public BlockingQueue<Material, Material> {
    private:
    std::vector<Material> materials;
    std::mutex notifierMutex;
    std::condition_variable sleepCondition;
    bool working = true;
    bool notified = false;

    public:
    MaterialQueue() : BlockingQueue<Material, Material>() {}
    void push(const Material elem);
    Maybe<Material> pop(Gatherer& worker);
    void shutdown();
    size_t size();

    protected:
    virtual void _pop(
        std::vector<std::pair<Material, size_t>>& materials,
        std::vector<Material>& toProcess);
    virtual void _push(const Material material);

};

#endif
