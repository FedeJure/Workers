#include <iostream>
#include "./Worker.h"

void Worker::work() {
    std::cout << "Working!!";
}

void Worker::startWorking() {
    this->thread = std::thread(Worker::work);
    this->thread.join();
}