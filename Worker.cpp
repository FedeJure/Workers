#include "./Worker.h"

Worker::Worker() {}

Worker::~Worker() {}

void Worker::waitUntilTerminate() {
    thread.join();
}

void Worker::start() {
    thread = std::thread(&Worker::work, this);
}
