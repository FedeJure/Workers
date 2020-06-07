#include <string>
#include "./Workers.h"
#include "./ArgumentParser.h"
#include "./DetailedException.h"

int main(int argc, char *argv[]) {
    try
    {
        ArgumentParser parser(argc, argv);
        Workers workers(parser.getMapFileName(), parser.getWorkersFileName());
    }
    catch(const DetailedException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...) {
        std::cerr << "Unknown error.\n";
    }
    return 0;
}
