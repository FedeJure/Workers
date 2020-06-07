#include <string>
#include <exception>
#include <iostream>
#include "./ArgumentParser.h"
#include "./DetailedException.h"

ArgumentParser::ArgumentParser(int argc, char* argv[]) {
    if (argc != 3) throw DetailedException("Invalid args was passed.");
    workersFileName = std::string(argv[1]);
    mapFileName = std::string(argv[2]);
}

std::string& ArgumentParser::getMapFileName() {
    return mapFileName;
}
std::string& ArgumentParser::getWorkersFileName() {
    return workersFileName;
}
