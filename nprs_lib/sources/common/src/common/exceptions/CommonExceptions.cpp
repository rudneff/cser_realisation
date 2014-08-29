#include "CommonExceptions.h"

namespace nprs {
    
nprs::ArgumentException::ArgumentException(const std::string& message)
: NprsException(message)
{}

nprs::NotSupportedException::NotSupportedException(std::string const& message)
: NprsException(message)
{}

NotImplementedException::NotImplementedException(std::string const& message)
: NprsException(message) 
{}

WrongStateException::WrongStateException(std::string const& message)
: NprsException(message) 
{}

}
