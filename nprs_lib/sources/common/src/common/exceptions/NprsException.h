#ifndef COMMON_NPRSEXCEPTION_H
#define COMMON_NPRSEXCEPTION_H

#include <string>
#include <stdexcept>

namespace nprs {

class NprsException : public std::runtime_error {
public:
    explicit NprsException(const std::string &message);
};

}

#endif // COMMON_NPRSEXCEPTION_H
