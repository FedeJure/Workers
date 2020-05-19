#include "./Worker.h"
#include "../Works/WheatQueue.h"

class Farmer: public Worker {

    public:
    Farmer(WheatQueue provider) : Worker(provider) {
    }

    void startWorking() {
        this->provider.consume();
    };
};