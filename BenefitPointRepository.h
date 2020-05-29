#ifndef BENEFIT_POINT_REPOSITORY
#define BENEFIT_POINT_REPOSITORY

#include <mutex>

enum BenefitPoints {
    ChefPoint = 5,
    CarpenterPoint = 2,
    WeaponsmithPoints = 3
};
class BenefitPointRepository {
    int points;
    std::mutex m;
    
    public:
    BenefitPointRepository() {}
    void add(BenefitPoints value);
    int get();
};

#endif