#include "argparser/internal/StringArgumentParser.hpp"

#include <iostream>

namespace ArgumentParser
{

namespace InternalAP
{
    std::string StringArgumentParser::parseStringValue(const std::string& flagNameAndValue) const
    {
        std::size_t valueLocation = flagNameAndValue.find("=") + 1;
        return flagNameAndValue.substr(valueLocation);
    }
}

}
