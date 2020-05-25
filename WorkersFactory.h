#ifndef WORKERS_FACTORY_H_
#define WORKERS_FACTORY_H_

#include <fstream>
#include <string>
#include <regex>
#include <iostream>
#include <map>

class WorkersFactory {
    std::ifstream file;
    std::map<std::string, int> spawnMap;
    public:
    WorkersFactory(int farmers, int woodcutters, int miners) :
                                    file("trabajadores.txt"){}

    void createWorkersFromFile();

    ~WorkersFactory() {
        file.close();
    }
};

#endif