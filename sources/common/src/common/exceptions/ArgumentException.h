#ifndef COMMON_ARGUMENTEXCEPTION_H
#define COMMON_ARGUMENTEXCEPTION_H

#include <common/exceptions/NprsException.h>

namespace nprs {

class ArgumentException : public NprsException {
public:
    ArgumentException(std::string const& message);
};

}

#endif // COMMON_ARGUMENTEXCEPTION_H