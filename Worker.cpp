#include <iostream>
#include "./Worker.h"

void Gatherer::saveWork(Material value) {
    this->inventory->add(value);
} 