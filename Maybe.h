#ifndef MAYBE_H_
#define MAYBE_H_

template<typename T>
class Maybe {
    private:
        T value;
        bool empty;
    public:
    explicit Maybe(T& providedValue) : empty(false) {value = providedValue;}
    Maybe() : empty(true) {}
    bool hasValue() {return !empty;}
    T getValue() { return this->value; }
    void setValue(T providedValue) { value = providedValue; }
    static Maybe<T> nothing() { 
        Maybe<T> nothing;
        return nothing;
    }
};

#endif
