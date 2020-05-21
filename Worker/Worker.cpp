#include <iostream>
#include "./Worker.h"

void Worker::work() {
    std::chrono::milliseconds dura( 2000 );
    std::this_thread::sleep_for(dura);
    Wheat w = this->queue->consume();
    std::cout << "Working!! " << w;
}

void Worker::startWorking() {
    std::cout << "start working";
    this->thread = std::thread(&Worker::work, this);
    // this->thread = std::thread(work, this);
    // this->thread.join();
    this->thread.join();   
}