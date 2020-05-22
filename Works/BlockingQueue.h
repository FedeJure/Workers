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
    std::mutex m;
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
        {
            std::unique_lock<std::mutex> lock(m);
            queue.push(elem);
            notified = true;
        }
        notEmpty.notify_one();


    }

    inline Maybe<T> pop() {
        while(!isNotified()) {
            if (isEmpty()) {
                if (!isRunning()) {
                    Maybe<T> nothing; 
                    return nothing;
                }
                continue;
            }
            std::unique_lock<std::mutex> lock(m);
            notEmpty.wait(lock);
            notified = false;
        }
        if (isEmpty()) return T(); 
        T value = std::move(this->queue.front());
        Maybe<T> toReturn(value);
        queue.pop();
        return toReturn;
    }

    inline void shutdown() {
        {
            std::unique_lock<std::mutex> lock(m);
            working = false;
            lock.unlock();
        }
        notEmpty.notify_all();

    }

    inline bool isRunning() {
        {
            std::unique_lock<std::mutex> lock(m);
            bool toReturn = working;
            lock.unlock();
            return toReturn;
        }
    }
};


#endif