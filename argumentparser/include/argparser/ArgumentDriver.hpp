#ifndef ARGUMENT_DRIVER_HPP
#define ARGUMENT_DRIVER_HPP

#include <map>
#include <string>
#include <memory>

#include "argparser/internal/BoolArgumentParser.hpp"
#include "argparser/internal/IntArgumentParser.hpp"
#include "argparser/internal/StringArgumentParser.hpp"

namespace ArgumentParser
{

class ArgumentDriver
{
public:
    ArgumentDriver();

    ~ArgumentDriver() = default;

    /*
     * Client passes in arguments and it gets parsed internally 
     * @param [in] argc: Number of arguments in argv
     * @param [in] argv: Arguments stored in a C-string array
     */
    void parseArguments(int argc, char* argv[]);

    /*
     * Getter functions for arguments parsed
     */
    bool getBoolArg(const std::string& flagName);
    std::string getStringArg(const std::string& flagName);
    int getIntArg(const std::string& flagName);

private:

    std::map<std::string, bool> boolArgMap;
    std::map<std::string, std::string> stringArgMap;
    std::map<std::string, int> intArgMap;

    std::unique_ptr<InternalAP::BoolArgumentParser> boolParser;
    std::unique_ptr<InternalAP::IntArgumentParser> intParser;
    std::unique_ptr<InternalAP::StringArgumentParser> stringParser;

    void runArgumentParsing(const std::string& flagType, const std::string& flagAndValue);
    bool parseBoolArg(const std::string& flagNameAndValue) const;
    std::string parseStringArg(const std::string& flagNameAndValue) const;
    int parseIntArg(const std::string& flagNameAndValue) const;
    
    std::string parseFlagName(const std::string& flagAndValue) const;

};

}

#endif
