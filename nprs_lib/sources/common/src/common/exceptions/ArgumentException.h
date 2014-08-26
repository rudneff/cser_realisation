#ifndef COMMON_ARGUMENTEXCEPTION_H
#define COMMON_ARGUMENTEXCEPTION_H

#include <common/exceptions/NprsException.h>

namespace nprs {

class ArgumentException : public NprsException {
public:
    explicit ArgumentException(const std::string &message);
    ArgumentException(const std::string &message, std::exception_ptr innerException);
};

}

#endif // COMMON_ARGUMENTEXCEPTION_H