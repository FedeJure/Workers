#include <thread>
#include "./WorkProvider.h"

class Worker {
    protected:
    const std::thread thread;
    const WorkProvider provider;

    public:
    Worker(WorkProvider provider) : thread(std::thread(startWorking)), provider(provider) {

    };

    ~Worker() {
        
    }
    void startWorking();
};