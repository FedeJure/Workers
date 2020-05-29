#include "./Gatherer.h"

void Gatherer::saveWork(Material value) {
    this->inventory->add(value);
}
