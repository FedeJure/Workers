#ifndef ARGUMENT_PARSER_H_
#define ARGUMENT_PARSER_H_
#include <string>

class ArgumentParser {
    std::string mapFileName;
    std::string workersFileName;
    public:
    ArgumentParser(int argc, char* argv[]);
    std::string& getMapFileName();
    std::string& getWorkersFileName();
};

#endif
