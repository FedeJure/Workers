#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <string>

class Material {
    public:
    virtual std::string toString() = 0;
};

class Wheat : public Material {
    public:
    virtual std::string toString() {
        return "Wheat";
    }
};

class Wood: public Material {
    public:
    virtual std::string toString() {
        return "Wood";
    }
};

class Iron: public Material {
    public:
    virtual std::string toString() {
        return "Iron";
    }
};

class Coal: public Material {
    public:
    virtual std::string toString() {
        return "Coal";
    }
};


#endif