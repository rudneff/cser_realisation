#ifndef COMMON_NPRSEXCEPTION_H
#define COMMON_NPRSEXCEPTION_H

#include <string>

namespace nprs {

class NprsException {
public:
    NprsException(const std::string &message);
     
private:
    std::string _message;
};

}

#endif // COMMON_NPRSEXCEPTION_H