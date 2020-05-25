#ifndef BLOCKING_QUEUE_H_
#define BLOCKING_QUEUE_H_
#include <mutex>
#include <condition_variable>
#include <queue>
#include <iostream>
#include <thread>
#include "./Maybe.h"

template<typename T>
class BlockingQueue {
    protected:
    std::queue<T> queue;
    std::mutex notifierMutex;
    std::condition_variable notEmpty;
    bool working = true;
    bool notified = false;

    public:
    inline BlockingQueue(){}

    inline void push(const T elem) {
        std::unique_lock<std::mutex> lock(notifierMutex);
        _push(elem);
        notEmpty.notify_all();
        notified = true;
    }

    inline Maybe<T> pop() {
        std::unique_lock<std::mutex> lock(notifierMutex);
        while(conditionToStop()) {
            if (!working) {
                return Maybe<T>::nothing();
            }
            while(!notified) {
                notEmpty.wait(lock);
            }
        }
        notified = false;
        T value = _pop();
        Maybe<T> toReturn(value);
        return toReturn;
    }

    inline void shutdown() {
        std::unique_lock<std::mutex> lock(notifierMutex);
        working = false;
        notEmpty.notify_all();
    }

    protected:
    virtual bool conditionToStop() {
        return this->queue.empty();
    }

    virtual T _pop() {
        std::unique_lock<std::mutex> lock(notifierMutex);
        T toReturn = queue.front();
        queue.pop();
        return toReturn;
    }

    virtual void _push(T element) {
        std::unique_lock<std::mutex> lock(notifierMutex);
        queue.push(element);
    }
};

#endif
