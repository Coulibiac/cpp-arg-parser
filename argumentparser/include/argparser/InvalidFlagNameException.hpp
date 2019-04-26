#ifndef INVALID_FLAG_NAME_EXCEPTION_HPP
#define INVALID_FLAG_NAME_EXCEPTION_HPP

#include <exception>

namespace ArgumentParser
{
class InvalidFlagNameException : public std::exception
{
public:
    InvalidFlagNameException() : msg("Invalid flag name") {}

    InvalidFlagNameException(std::string msg) : msg(msg) {}

    const char* what() const throw()
    {
        return msg.c_str();
    }

private:
    std::string msg;
};
}

#endif // INVALID_FLAG_NAME_EXCEPTION_HPP
