#ifndef BLOCKING_QUEUE_H_
#define BLOCKING_QUEUE_H_
#include <mutex>
#include <condition_variable>
#include <deque>
#include <iostream>

template<typename T>
class BlockingQueue {
    private: 
    std::mutex m;
    std::deque<T> queue;
    std::condition_variable codition;
    bool notified = false;

    public:
    BlockingQueue() : queue() {}
    T pop();
    void push(T const& object);
    ~BlockingQueue() {}
};

template <typename T>
T BlockingQueue<T>::pop() {
    std::cout << "Pop!";
    std::unique_lock<std::mutex> lock(this->m);
    while (!notified)
    {
        this->codition.wait(lock);        
    }
    std::fflush(stdout);

    T toReturn(std::move(this->queue.front()));
    this->queue.pop_front();
    this->notified = false;
    return toReturn;
}

template <typename T>
void BlockingQueue<T>::push(T const &object) {
    std::unique_lock<std::mutex> lock(this->m);
    this->queue.push_back(object);
    this->notified = true;
    this->codition.notify_one();
    std::cout << "push";
    fflush(stdout);
}

#endif