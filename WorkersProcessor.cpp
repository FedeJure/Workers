#include <string>
#include <iostream>
#include "./WorkersProcessor.h"

WorkersFactory::WorkersFactory(WorkerSpawner* spawner,
                            std::string& fileName) 
    : file(fileName) {
        this->spawner = spawner;
        for (std::string key : keys) {
            spawnMap[key] = 0;
        }
        this->createWorkersFromFile();
}

WorkersFactory::~WorkersFactory() {
    file.close();
}

void WorkersFactory::createWorkersFromFile() {
    std::string line;
    while (std::getline(file, line)) {
        int separator = line.find("=");
        std::string type = line.substr(0, separator);
        int count = std::stoi(line.substr(separator + 1, line.size() + 1));
        spawnMap[type] += count;
    }
    spawner->spawnWorkers(spawnMap[keys[0]], spawnMap[keys[1]],
                            spawnMap[keys[2]], spawnMap[keys[3]],
                            spawnMap[keys[4]], spawnMap[keys[5]]);
    file.close();
}
