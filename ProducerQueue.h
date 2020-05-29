#ifndef PRODUCER_QUEUE_H_
#define PRODUCER_QUEUE_H_

#include "./Material.h"
#include "./BlockingQueue.h"
#include "./Inventory.h"
#include "./BenefitPointRepository.h"
#include "./Observer.h"


class ChefQueue: public BlockingQueue<Material, BenefitPoints>, Observer {
    Inventory* inventory;
    public:
    ChefQueue(Inventory& inventory) : BlockingQueue<Material, BenefitPoints>() {
        this->inventory = &inventory;
        this->inventory->addObserver(*this);
    }
    Maybe<BenefitPoints> pop();
    virtual BenefitPoints _pop();
    virtual bool _continueCondition();
    virtual void notify();
};

class CarpenterQueue: public BlockingQueue<Material, BenefitPoints>, Observer{
    Inventory* inventory;
    public:
    CarpenterQueue(Inventory& inventory) : BlockingQueue<Material, BenefitPoints>() {
        this->inventory = &inventory;
        this->inventory->addObserver(*this);
    }
    Maybe<BenefitPoints> pop();

    virtual BenefitPoints _pop();
    virtual bool _continueCondition();
    virtual void notify();
};

class WheaponsmithQueue: public BlockingQueue<Material, BenefitPoints>, Observer {
    Inventory* inventory;
    public:
    WheaponsmithQueue(Inventory& inventory) : BlockingQueue<Material, BenefitPoints>() {
        this->inventory = &inventory;
        this->inventory->addObserver(*this);
    }
    Maybe<BenefitPoints> pop();

    virtual BenefitPoints _pop();
    virtual bool _continueCondition();
    virtual void notify();
};

#endif