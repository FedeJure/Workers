#include "./Worker.h"

void Worker::waitUntilTerminate() {
    thread.join();
}

void Worker::start() {
    thread = std::thread(&Worker::work, this);
}
