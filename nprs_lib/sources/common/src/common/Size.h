#ifndef COMMON_SIZE_H
#define COMMON_SIZE_H

namespace nprs {

class Size {
public:
    Size(int size);
    Size(int width, int height);

    int width();
    int height();

private:
    int _width;
    int _height;
};

#include "Size.inl"

}

#endif // COMMON_SIZE_H
