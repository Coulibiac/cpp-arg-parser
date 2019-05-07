#ifndef BOOL_ARGUMENT_PARSER_HPP
#define BOOL_ARGUMENT_PARSER_HPP

#include "argparser/internal/ArgumentParser.hpp"
#include <string>

namespace ArgumentParser
{

namespace InternalAP
{

class BoolArgumentParser : public ArgumentParser
{
public:

    BoolArgumentParser() = default;

    ~BoolArgumentParser() = default;

    bool parseBoolValue(const std::string& flagNameAndValue) const;

};

}

}

#endif // BOOL_ARGUMENT_PARSER_HPP
