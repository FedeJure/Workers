#include <string>
#include <iostream>
#include "./WorkersFactory.h"

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
}
