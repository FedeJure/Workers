#ifndef PRODUCER_QUEUE_H_
#define PRODUCER_QUEUE_H_

#include "./Material.h"
#include "./BlockingQueue.h"
#include "./Inventory.h"

enum BenefitPoints {
    ChefPoint = 5,
    CarpenterPoint = 2,
    WeaponsmithPoints = 3
};

template<>
class BlockingQueue<Material, BenefitPoints> {

    public:
    BlockingQueue() { }

    protected:
    virtual BenefitPoints _pop() = 0;
    virtual bool _continueCondition() = 0;

};

class ChefQueue: BlockingQueue<Material, BenefitPoints> {
    Inventory* inventory;
    public:
    ChefQueue(Inventory& inventory) : BlockingQueue<Material, BenefitPoints>() {
        this->inventory = &inventory;
    }

    virtual BenefitPoints _pop();
    virtual bool _continueCondition();
};

class CarpenterQueue: BlockingQueue<Material, BenefitPoints> {
    Inventory* inventory;
    public:
    CarpenterQueue(Inventory& inventory) : BlockingQueue<Material, BenefitPoints>() {
        this->inventory = &inventory;
    }

    virtual BenefitPoints _pop();
    virtual bool _continueCondition();
};

class WheaponsmithQueue: BlockingQueue<Material, BenefitPoints> {
    Inventory* inventory;
    public:
    WheaponsmithQueue(Inventory& inventory) : BlockingQueue<Material, BenefitPoints>() {
        this->inventory = &inventory;
    }

    virtual BenefitPoints _pop();
    virtual bool _continueCondition();
};

#endif