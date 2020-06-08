#include <vector>
#include <iostream>
#include "./Woodcutter.h"

Woodcutter::Woodcutter(BlockingQueue& providedQueue,
    BlockingQueue& repository)
    : Gatherer(providedQueue,repository) {}

Woodcutter::~Woodcutter() {
    std::cout<<"Destruye woodcutter";
}

std::vector<QueueRequestDto> Woodcutter::requiredMaterials() {
    std::vector<QueueRequestDto> materials;
    materials.push_back(QueueRequestDto(Coal, 1));
    return materials;
}
