#include "./Gatherer.h"

void Gatherer::work() {
    bool working = true;
    while (working) {
        Maybe<Material> value = this->queue->pop(*this);
        if (value.hasValue()) { 
            std::chrono::milliseconds work_time(50);
            std::this_thread::sleep_for(work_time);
            this->inventory->push(value.getValue());
        } else {
            working = false;
        }
    }
}



bool Gatherer::continueCondition(MaterialQueue& queue) {
    return queue.size() > 0;
}
