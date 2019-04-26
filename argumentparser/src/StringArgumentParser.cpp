#include "argparser/internal/StringArgumentParser.hpp"

#include <iostream>

namespace ArgumentParser
{

namespace InternalAP
{
    std::string StringArgumentParser::parseStringValue(std::string flagNameAndValue)
    {
        std::size_t valueLocation = flagNameAndValue.find("=") + 1;
        return flagNameAndValue.substr(valueLocation);
    }
}

}
