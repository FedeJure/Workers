#include <string>
#include "./Main.h"
#include "./Workers.h"

int main(int argc, char *argv[]) {
    try
    {
        std::string mapFileName;
        std::string workersFileName;
        parseArguments(argc, argv, workersFileName, mapFileName);
        
        Workers workers(mapFileName, workersFileName);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...) {
        std::cerr << "Unknown error.\n";
    }
    return 0;
}

void parseArguments(int argc, char *argv[],
    std::string& workersFile, std::string& map) {
    if (argc != 3) throw InvalidArgumentsError("Invalid args was passed.");
    std::string aux(argv[1]);
    workersFile = aux;
    std::string aux1(argv[2]);
    map = aux1;
}
