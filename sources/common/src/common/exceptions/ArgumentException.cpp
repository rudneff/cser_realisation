#include "ArgumentException.h"

nprs::ArgumentException::ArgumentException(const std::string& message)
    : NprsException(message) 
{}

nprs::ArgumentException::ArgumentException(std::string const& message, std::exception_ptr innerException) 
    : NprsException(message, innerException)
{}
