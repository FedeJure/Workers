#ifndef BENEFIT_POINT_REPOSITORY
#define BENEFIT_POINT_REPOSITORY

#include <mutex>

class BenefitPointRepository {
    int points;
    std::mutex m;
    
    public:
    BenefitPointRepository() {}
    void add(int value);
    int get();
};

#endif