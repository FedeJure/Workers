#include "./Producer.h"

void Producer::saveWork(BenefitPoints points) {
    std::cout<<"Saving work!";
    this->repository->add(points);
}