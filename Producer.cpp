#include "./Producer.h"

void Producer::saveWork(BenefitPoints points) {
    this->repository->add(points);
}

void Producer::work() {
    std::cout << "Working!! \n";
    fflush(stdout);
    while(1) {
        Maybe<BenefitPoints> value = this->queue->pop();
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