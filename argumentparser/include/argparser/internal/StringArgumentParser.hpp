#ifndef STRING_ARGUMENT_PARSER_HPP
#define STRING_ARGUMENT_PARSER_HPP

#include "argparser/internal/ArgumentParser.hpp"
#include <string>

namespace ArgumentParser
{

namespace InternalAP
{

class StringArgumentParser : public ArgumentParser
{
public: 

    StringArgumentParser() = default;

    ~StringArgumentParser() = default;

    std::string parseStringValue(const std::string& flagNameAndValue) const;

};

}

}

#endif // STRING_ARGUMENT_PARSER_HPP
