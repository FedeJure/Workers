#include "./MaterialQueue.h"
#include "./Material.h"

class ProvideResource {
    MaterialQueue* queue;
    Material mat;
    public:
    ProvideResource(MaterialQueue& q, Material mat) { 
        this->queue = &q; 
        this->mat = mat;
    } 
    void operator()() {
        queue->push(mat);
    }
    ~ProvideResource() {
        queue->shutdown();
    }
};