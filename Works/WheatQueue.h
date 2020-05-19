#include "./WorkProvider.h"
#include <mutex>



class WheatQueue {
    WorkProvider provider;

    public:
    WheatQueue() : provider() {}

    int consume();
    void provide(int count);

    ~WheatQueue() {};
};