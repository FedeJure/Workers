#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <string>

class Material {
    public:
    virtual std::string toString() {
        return "Material";
    };
};

class Wheat : public Material {
    public:
    Wheat() {}
    virtual std::string toString() {
        return "Wheat";
    }
};

class Wood: public Material {
    public:
    Wood() {}
    virtual std::string toString() {
        return "Wood";
    }
};

class Iron: public Material {
    public:
    Iron() {}
    virtual std::string toString() {
        return "Iron";
    }
};

class Coal: public Material {
    public:
    Coal() {}
    virtual std::string toString() {
        return "Coal";
    }
};


#endif