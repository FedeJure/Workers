#ifndef WORK_PROVIDER_H_
#define WORK_PROVIDER_H_
#include <mutex>
#include <iostream>

class WorkProvider {
    private: 
    int count;
    std::mutex m;

    public:
    WorkProvider() : count(0) {}
    int consume();
    void provide(int count);
    ~WorkProvider() {}
};

#endif