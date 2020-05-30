#ifndef PROTECTED_MAP_H_
#define PROTECTED_MAP_H_
#include <map>
#include <utility>
#include <initializer_list>
#include <mutex>

template<typename K, typename V>
class ProtectedMap {
    std::map<K, V> container;
    std::mutex m;


    public:
    ProtectedMap(std::initializer_list<std::pair<K,V>> list): container(list) {

    }

    V* get(K key) {
        std::unique_lock<std::mutex>(m);
        return &container[key];
    }

    void set(K key, V value) {
        std::unique_lock<std::mutex>(m);
        container[key] = value;
    }
};


#endif