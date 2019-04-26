#ifndef ARGUMENT_PARSER_HPP
#define ARGUMENT_PARSER_HPP

namespace ArgumentParser
{

/*
 * This class is to be inherited from by other parser objects to implement the parsing logic
 */
class ArgumentParser
{
public:

    ArgumentParser() = default;

    virtual ~ArgumentParser() = default;

};

} // Namespace ArgumentParser

#endif // ARGUMENT_PARSER_HPP
