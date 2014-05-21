#include "ArgumentException.h"

nprs::ArgumentException::ArgumentException(const std::string& message)
    : NprsException(message) 
{}