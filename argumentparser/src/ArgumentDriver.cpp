#include "argparser/ArgumentDriver.hpp"
#include "argparser/InvalidFlagNameException.hpp"
#include "argparser/ArgumentMissingException.hpp"

#include <iostream>

namespace ArgumentParser
{
ArgumentDriver::ArgumentDriver()
    : boolParser(std::make_unique<InternalAP::BoolArgumentParser>()), 
    intParser(std::make_unique<InternalAP::IntArgumentParser>()), 
    stringParser(std::make_unique<InternalAP::StringArgumentParser>())
{
    
}

bool ArgumentDriver::getBoolArg(const std::string& flagName)
{
    if (boolArgMap.find(flagName) != boolArgMap.end())
    {
        return boolArgMap[flagName];
    }
    else
    {
        throw ArgumentMissingException("No bool arg for flag name: " + flagName);
    }
}

std::string ArgumentDriver::getStringArg(const std::string& flagName)
{
    if (stringArgMap.find(flagName) != stringArgMap.end())
    {
        return stringArgMap[flagName];
    }
    else
    {
        throw ArgumentMissingException("No string arg for flag name: " + flagName);
    }
}

int ArgumentDriver::getIntArg(const std::string& flagName)
{
    if (intArgMap.find(flagName) != intArgMap.end())
    {
        return intArgMap[flagName];
    }
    else
    {
        throw ArgumentMissingException("No int arg for flag name: " + flagName);
    }
}

void ArgumentDriver::parseArguments(int argc, char* argv[])
{
    for (int i = 1; i < argc; i += 2)
    {
        runArgumentParsing(argv[i], argv[i+1]);
    }
}

bool ArgumentDriver::parseBoolArg(const std::string& flagNameAndValue) const
{
    std::cout << "Flag name is: " << flagNameAndValue << std::endl;
    return boolParser->parseBoolValue(flagNameAndValue);
}

std::string ArgumentDriver::parseStringArg(const std::string& flagNameAndValue) const
{
    std::cout << "Flag name is: " << flagNameAndValue << std::endl;
    return stringParser->parseStringValue(flagNameAndValue);
}

int ArgumentDriver::parseIntArg(const std::string& flagNameAndValue) const
{
    std::cout << "Flag name is: " << flagNameAndValue << std::endl;
    return intParser->parseIntValue(flagNameAndValue);
}

void ArgumentDriver::runArgumentParsing(const std::string& flagType, const std::string& flagAndValue)
{
    std::string flagName = parseFlagName(flagAndValue);
    if (flagType == "-b")
    {
        bool flagValue = parseBoolArg(flagAndValue);
        boolArgMap.emplace(std::make_pair(flagName, flagValue));
    }
    else if (flagType == "-i")
    {
        int flagValue = parseIntArg(flagAndValue);
        intArgMap.emplace(std::make_pair(flagName, flagValue));
    }
    else if (flagType == "-s")
    {
        std::string flagValue = parseStringArg(flagAndValue);
        stringArgMap.emplace(std::make_pair(flagName, flagValue));
    }
    else
    {
        throw InvalidFlagNameException("Flag type was not one of : b, i, or s");
    }
}

std::string ArgumentDriver::parseFlagName(const std::string& flagAndValue) const
{
    std::size_t equalsPos = flagAndValue.find("=");
    return flagAndValue.substr(0, equalsPos);
}

}
