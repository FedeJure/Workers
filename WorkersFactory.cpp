#include "./WorkersFactory.h"

void WorkersFactory::createWorkersFromFile() {
    std::string line;
    std::regex reg("([1-9][0-9]*)");
    std::smatch match;
    while (getline(file, line)) {
        int separator = line.find("=");
        std::string type = line.substr(0, separator);
        int count = std::stoi(line.substr(separator + 1, line.size() + 1));
        std::cout << count;
    }
}