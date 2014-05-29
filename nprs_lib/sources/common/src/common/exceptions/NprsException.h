#ifndef COMMON_NPRSEXCEPTION_H
#define COMMON_NPRSEXCEPTION_H

#include <string>

namespace nprs {

class NprsException {
public:
    explicit NprsException(const std::string &message);
    NprsException(const std::string &message, std::exception_ptr innerException);

    std::string const& getMessage() { return _message; }
    std::exception_ptr getInnerException() { return _innerException; }

private:
    std::string _message;
    std::exception_ptr _innerException;
};

}

#endif // COMMON_NPRSEXCEPTION_H