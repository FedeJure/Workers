#ifndef PRODUCER_QUEUE_H_
#define PRODUCER_QUEUE_H_

#include "./Material.h"
#include "./BlockingQueue.h"
#include "./Inventory.h"
#include "./BenefitPointRepository.h"


class ChefQueue: public BlockingQueue<Material, BenefitPoints> {
    Inventory* inventory;
    public:
    ChefQueue(Inventory& inventory) : BlockingQueue<Material, BenefitPoints>() {
        this->inventory = &inventory;
    }
    Maybe<BenefitPoints> pop();
    virtual BenefitPoints _pop();
    virtual bool _continueCondition();
};

class CarpenterQueue: public BlockingQueue<Material, BenefitPoints> {
    Inventory* inventory;
    public:
    CarpenterQueue(Inventory& inventory) : BlockingQueue<Material, BenefitPoints>() {
        this->inventory = &inventory;
    }
    Maybe<BenefitPoints> pop();

    virtual BenefitPoints _pop();
    virtual bool _continueCondition();
};

class WheaponsmithQueue: public BlockingQueue<Material, BenefitPoints> {
    Inventory* inventory;
    public:
    WheaponsmithQueue(Inventory& inventory) : BlockingQueue<Material, BenefitPoints>() {
        this->inventory = &inventory;
    }
    Maybe<BenefitPoints> pop();

    virtual BenefitPoints _pop();
    virtual bool _continueCondition();
};

#endif