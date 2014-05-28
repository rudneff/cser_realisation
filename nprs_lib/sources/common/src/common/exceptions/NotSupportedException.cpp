#include "NotSupportedException.h"

nprs::NotSupportedException::NotSupportedException(std::string const& message)
    : NprsException(message) 
{}

nprs::NotSupportedException::NotSupportedException(std::string const& message, std::exception_ptr innerException) 
    : NprsException(message, innerException)
{
}
