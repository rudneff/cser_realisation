#ifndef RECSYSTEM_NUMBERPLATECHARACTER_H
#define RECSYSTEM_NUMBERPLATECHARACTER_H

#include "common/Rectangle.h"

namespace nprs {

class NumberPlateCharacter {
public:
    NumberPlateCharacter(short code, const Rectangle &bounds)
        : _code(code), _bounds(bounds)
    {}

    short code() const { return _code; }
    Rectangle const & bounds() const { return _bounds; }

private:
    short _code;
    Rectangle _bounds;
};

}

#endif