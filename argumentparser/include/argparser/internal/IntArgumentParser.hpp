#ifndef INT_ARGUMENT_PARSER_HPP
#define INT_ARGUMENT_PARSER_HPP

#include "argparser/internal/ArgumentParser.hpp"
#include <string>

namespace ArgumentParser
{

namespace InternalAP
{

class IntArgumentParser : public ArgumentParser
{
public:

    IntArgumentParser() = default;

    ~IntArgumentParser() = default;

    int parseIntValue(std::string flagNameAndValue);
};

}

}

#endif // INT_ARGUMENT_PARSER_HPP
