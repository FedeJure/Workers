#include <iostream>
#include "./Worker.h"

void Worker::work() {
    std::cout << "Working!! \n";
    fflush(stdout);
    while(1) {
        Maybe<Material> value = this->queue->pop();
        if (value.hasValue()) { 
            std::chrono::milliseconds work_time(50);
            std::this_thread::sleep_for(work_time);  
            this->inventory->add(*value.getValue());
        }
        else break;
    }
    std::cout << "stop working\n";
    fflush(stdout);
}

void Worker::waitUntilTerminate() {
    this->thread.join();
}