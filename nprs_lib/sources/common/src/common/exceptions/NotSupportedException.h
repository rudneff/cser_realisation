#ifndef COMMON_NOTSUPPORTEDEXCEPTION_H
#define COMMON_NOTSUPPORTEDEXCEPTION_H

#include <common/exceptions/NprsException.h>

namespace nprs {

class NotSupportedException : public NprsException {
public:
    explicit NotSupportedException(std::string const& message);
    NotSupportedException(std::string const& message, std::exception_ptr innerException);
};

}

#endif // NOTSUPPORTEDEXCEPTION_H
