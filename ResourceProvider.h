#include "./BlockingQueue.h"
#include "./Material.h"

class ProvideResource {
    BlockingQueue<Material>* queue;
    Material mat;
    public:
    ProvideResource(BlockingQueue<Material>& q, Material mat) { 
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