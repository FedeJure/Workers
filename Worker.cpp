#include "./Worker.h"

void Worker::waitUntilTerminate() {
    thread.join();
}