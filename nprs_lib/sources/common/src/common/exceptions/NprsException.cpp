#include "NprsException.h"

nprs::NprsException::NprsException(std::string const& message) 
: std::runtime_error(message)
{}