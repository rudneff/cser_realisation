#ifndef RECSYSTEM_NUMBERPLATECHARACTER_H
#define RECSYSTEM_NUMBERPLATECHARACTER_H

#include "common/Rectangle.h"

namespace nprs {

class NumberPlateCharacter {
public:
    NumberPlateCharacter(int code, const Rectangle &bounds);

    int code() const { return _code; }
    Rectangle const & bounds() const { return _bounds; }

private:
    int _code;
    Rectangle _bounds;
};

}

#endif
