#ifndef COMMON_COMMONEXCEPTIONS_H
#define COMMON_COMMONEXCEPTIONS_H

#include <common/exceptions/NprsException.h>

namespace nprs {

class ArgumentException : public NprsException {
public:
    explicit ArgumentException(const std::string &message);
};

class NotSupportedException : public NprsException {
public:
    explicit NotSupportedException(std::string const& message);
};

class NotImplementedException : public NprsException {
public:
    explicit NotImplementedException(std::string const& message);
};

class WrongStateException : public NprsException {
public:
    explicit WrongStateException(std::string const& message);
};

}

#endif // COMMON_COMMONEXCEPTIONS_H
