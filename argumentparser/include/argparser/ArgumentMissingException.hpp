#ifndef ARGUMENT_MISSING_EXCEPTION_HPP
#define ARGUMENT_MISSING_EXCEPTION_HPP

#include <exception>

namespace ArgumentParser
{
class ArgumentMissingException : public std::exception
{
public:
    ArgumentMissingException() : msg("Invalid argument type") {}

    ArgumentMissingException(std::string msg) : msg(msg) {}

    const char* what() const throw()
    {
        return msg.c_str();
    }

private:
    std::string msg;
};
}

#endif // ARGUMENT_MISSING_EXCEPTION_HPP
