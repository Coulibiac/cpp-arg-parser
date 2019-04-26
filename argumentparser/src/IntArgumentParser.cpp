#include "argparser/internal/IntArgumentParser.hpp"

#include <iostream>

namespace ArgumentParser
{

namespace InternalAP
{

int IntArgumentParser::parseIntValue(std::string flagNameAndValue)
{
    std::size_t valueLocation = flagNameAndValue.find("=") + 1;
    return stoi(flagNameAndValue.substr(valueLocation));
}


}

}

