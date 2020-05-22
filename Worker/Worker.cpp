#include <iostream>
#include "./Worker.h"

void Worker::work() {
    std::cout << "Working!! \n";
    fflush(stdout);
    while(this->queue->isRunning() || !this->queue->isEmpty()) {
        Wheat value = this->queue->consume();
        std::cout << "Work done: " << value << "\n";
        fflush(stdout);
        std::chrono::milliseconds work_time(50);
        std::this_thread::sleep_for(work_time);  
    }
    std::cout << "stop working\n";
    fflush(stdout);
}

void Worker::waitUntilTerminate() {
    this->thread.join();
}