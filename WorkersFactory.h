#ifndef WORKERS_FACTORY_H_
#define WORKERS_FACTORY_H_

#include <fstream>
#include <string>
#include <regex>
#include <map>
#include <vector>
#include "./GatherersSpawner.h"

class WorkersFactory {
    std::vector<std::string> keys =
                            {"Agricultores",
                            "Leniadores",
                            "Mineros",
                            "Cocineros",
                            "Carpinteros",
                            "Armeros"};
    std::ifstream file;
    std::map<std::string, int> spawnMap;
    GatherersSpawner* spawner;
    void createWorkersFromFile();

    public:
    explicit WorkersFactory(GatherersSpawner& spawner,
                            std::string& fileName) 
    : file(fileName) {
        this->spawner = &spawner;
        for (std::string key : keys) {
            spawnMap[key] = 0;
        }
        this->createWorkersFromFile();
    }


    ~WorkersFactory() {
        file.close();
    }
};

#endif
