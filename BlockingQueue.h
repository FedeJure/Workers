#ifndef BLOCKING_QUEUE_H_
#define BLOCKING_QUEUE_H_
#include <mutex>
#include <condition_variable>
#include <queue>
#include <iostream>
#include <thread>
#include "./Maybe.h"

template<typename T, typename U>
class BlockingQueue {
private:
    std::queue<T> queue;
    std::mutex notifierMutex;
    std::condition_variable notEmpty;
    bool working = true;
    bool notified = false;

public:
    inline BlockingQueue(){}

    inline void push(const T elem) {
        std::unique_lock<std::mutex> lock(notifierMutex);
        queue.push(elem);
        notEmpty.notify_all();
        notified = true;
    }

    inline Maybe<U> pop() {
        std::unique_lock<std::mutex> lock(notifierMutex);
        while(!_continueCondition()) {
            if (!working) {
                return Maybe<U>::nothing();
            }
            while(!notified) {
                notEmpty.wait(lock);
            }
        }
        notified = false;
        U aux = _pop();
        Maybe<U> toReturn(aux);
        return toReturn;
    }

    inline void shutdown() {
        std::unique_lock<std::mutex> lock(notifierMutex);
        working = false;
        notEmpty.notify_all();
    }
    virtual U _pop() {
        U aux = this->queue.front();
        this->queue.pop();
        return aux;
    };
    virtual bool _continueCondition() {
        return !this->queue.empty();
    }
};



#endif
