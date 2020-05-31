#ifndef MAIN_H_
#define MAIN_H_
#include <exception>
#include <string>
#include "./InventoryQueue.h"
#include "./MaterialQueue.h"
#include "./GatherersSpawner.h"
#include "./ResourcesProcessor.h"
#include "./WorkersFactory.h"

void parseArguments(int argc, char *argv[],
    std::string& workersFile, std::string& map);
class InvalidArgumentsError: virtual public std::exception {
    protected:
    std::string error_message;
    
    public:
    explicit InvalidArgumentsError(const std::string& msg):
        error_message(msg)
        {}

    virtual ~InvalidArgumentsError() throw() {}
    virtual const char* what() const throw() {
       return error_message.c_str();
    }
};
#endif
