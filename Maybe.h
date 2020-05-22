#ifndef MAYBE_H_
#define MAYBE_H_

template<typename T>
class Maybe {
    private:
        T value;
        bool empty;
    public:
    Maybe(T providedValue) : empty(false) {value = providedValue;}
    Maybe() : empty(true) {}
    bool hasValue() {return !empty;}
    T getValue() { return this->value; }
};

#endif