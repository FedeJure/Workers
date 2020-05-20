#ifndef FARMER_H_
#define FARMER_H_
#include <iostream>
#include "./Worker.h"

class Farmer: public Worker {

    public:
    Farmer(WheatQueue& provider) : Worker(provider) {
    }
};

#endif