#include <iostream>
#include "./Worker.h"

void Worker::work() {
    std::cout << "Working!! \n";
    fflush(stdout);
    while(this->queue->isRunning() || !this->queue->isEmpty()) {
        Maybe<Wheat> value = this->queue->consume();
        if (value.hasValue()) { 
            //guardar en inventario 
            std::cout << "Guardando en inventario: " << value.getValue();
        }
        std::chrono::milliseconds work_time(50);
        std::this_thread::sleep_for(work_time);  
    }
    std::cout << "stop working\n";
    fflush(stdout);
}

void Worker::waitUntilTerminate() {
    this->thread.join();
}