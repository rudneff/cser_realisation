#ifndef COMMON_ARGUMENTEXCEPTION_H
#define COMMON_ARGUMENTEXCEPTION_H

#include <common/exceptions/NprsException.h>

namespace nprs {

class ArgumentException : public NprsException {
public:
    explicit ArgumentException(std::string const& message);
    ArgumentException(std::string const& message, std::exception_ptr innerException);
};

}

#endif // COMMON_ARGUMENTEXCEPTION_H