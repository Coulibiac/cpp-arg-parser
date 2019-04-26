#include "argparser/internal/BoolArgumentParser.hpp"
#include "argparser/InvalidFlagNameException.hpp"

#include <iostream>

namespace ArgumentParser
{

namespace InternalAP
{

bool BoolArgumentParser::parseBoolValue(std::string flagNameAndValue)
{
    std::size_t valueLocation = flagNameAndValue.find("=") + 1;
    std::string boolValueAsString = flagNameAndValue.substr(valueLocation);
    if (boolValueAsString == "true")
    {
        return true;
    }
    else if (boolValueAsString == "false")
    {
        return false;
    }
    else
    {
        throw InvalidFlagNameException("Bad boolean value: " + boolValueAsString);
    }
}

}

}
