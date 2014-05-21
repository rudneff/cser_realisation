#ifndef RECSYSTEM_EXTREMALREGION_H
#define RECSYSTEM_EXTREMALREGION_H

#include <common/Rectangle.h>

namespace nprs {

class ExtremalRegion {
public:
    explicit ExtremalRegion(Rectangle const& rectangle);

private:
    Rectangle _bounds;
};

}

#endif // RECSYSTEM_EXTREMALREGION_H
