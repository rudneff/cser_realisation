#include "NprsException.h"

nprs::NprsException::NprsException(std::string const& message) 
    : _message(message)
{}

nprs::NprsException::NprsException(std::string const& message, std::exception_ptr innerException) 
    : _message(message), _innerException(innerException)
{
    
}