#ifndef BLOCKINGqueue_H_
#define BLOCKINGqueue_H_
#include <mutex>
#include <condition_variable>
#include <queue>
#include <iostream>
#include <thread>
#include "../Maybe.h"

template<typename T>
class BlockingQueue {
private:
    std::queue<T> queue;
    std::mutex notifierMutex;
    std::condition_variable notEmpty;
    bool working = true;
    bool notified = false;

    bool isNotified() {
        {
            return notified;
        }
    }

public:
    inline BlockingQueue(){}

    inline bool isEmpty() {
        {
            bool toReturn = this->queue.size() == 0;
            return toReturn;
        }

    }

    inline void push(const T elem) {
        std::unique_lock<std::mutex> lock(notifierMutex);
        queue.push(elem);
        notEmpty.notify_all();
        notified = true;
    }

    inline Maybe<T> pop() {
        std::unique_lock<std::mutex> lock(notifierMutex);
        while(isEmpty()) {
            if (!working) {
                return Maybe<T>::nothing();
            }
            while(!notified) {
                notEmpty.wait(lock);
            }
        }
        notified = false;
        Maybe<T> toReturn(this->queue.front());
        queue.pop();
        return toReturn;
    }

    inline void shutdown() {
        std::unique_lock<std::mutex> lock(notifierMutex);
        working = false;
        notEmpty.notify_all();
    }
};


#endif