#include <iostream>
#include "./Worker.h"

void Worker::work() {
    std::cout << "Working!! \n";
    fflush(stdout);
    while(this->queue->isRunning() || !this->queue->isEmpty()) {
        Wheat value = this->queue->consume();
        std::cout <<"thread id: "<<this->thread.get_id() << "Work done: " << value << "\n";
        fflush(stdout);
        std::chrono::milliseconds work_time(1000);
        std::this_thread::sleep_for(work_time);  
    }
    std::cout << "stop working\n";
    fflush(stdout);
}

void Worker::waitUntilTerminate() {
    this->thread.join();
}