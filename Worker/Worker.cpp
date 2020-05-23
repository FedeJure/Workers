#include <iostream>
#include "./Worker.h"

void Worker::work() {
    std::cout << "Working!! \n";
    fflush(stdout);
    while(1) {
        Maybe<int> value = this->queue->pop();
        if (value.hasValue()) { 
            this->inventory->add(WHEAT, value.getValue());
        }
        else break;
        std::chrono::milliseconds work_time(1000);
        std::this_thread::sleep_for(work_time);  
    }
    std::cout << "stop working\n";
    fflush(stdout);
}

void Worker::waitUntilTerminate() {
    this->thread.join();
}