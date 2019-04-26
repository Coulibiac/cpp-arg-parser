#include "argparser/ArgumentDriver.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << "Starting main test application" << std::endl;

    ArgumentParser::ArgumentDriver testDriver;
    testDriver.parseArguments(argc, argv);

    std::cout << testDriver.getStringArg("tester") << std::endl;
    std::cout << testDriver.getBoolArg("testBool") << std::endl;
    std::cout << testDriver.getIntArg("testInt") << std::endl;

    return 0;
}
