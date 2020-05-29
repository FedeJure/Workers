#include "./Gatherer.h"

void Gatherer::work() {
    std::cout << "Working!! Gatrherer\n";
    fflush(stdout);
    while(1) {
        Maybe<Material> value = this->queue->pop(*this);
        if (value.hasValue()) { 
            std::chrono::milliseconds work_time(50);
            std::this_thread::sleep_for(work_time);
            this->inventory->push(value.getValue());
        }
        else break;
    }
    std::cout << "stop working producer\n";
    fflush(stdout);
}
