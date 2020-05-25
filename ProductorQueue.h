#include "./BlockingQueue.h"
#include "./Inventory.h"

template<typename T>
class ChefQueue: public BlockingQueue<ChefPoint> {
    Inventory* inventory;
    public:
    ChefQueue(Inventory& inventory) { this->inventory = &inventory; }
    protected:
    virtual bool conditionToStop() {
        return !(inventory->count(Wheat) >= 2 && inventory->count(Coal) >= 1);
    }
    T _pop() {
        std::unique_lock<std::mutex> lock(notifierMutex);
        inventory->remove(Wheat, 2);
        inventory->remove(Coal, 1);
        return ;
    }

    void _push(T element) {
        std::unique_lock<std::mutex> lock(notifierMutex);
        queue.push(element);
    }
};