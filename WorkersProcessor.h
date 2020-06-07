#ifndef WORKERS_FACTORY_H_
#define WORKERS_FACTORY_H_

#include <fstream>
#include <string>
#include <regex>
#include <map>
#include <vector>
#include "./WorkerSpawner.h"

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
    WorkerSpawner* spawner;
    void createWorkersFromFile();

    public:
    explicit WorkersFactory(WorkerSpawner* spawner,
                            std::string& fileName);
    ~WorkersFactory();
};

#endif
