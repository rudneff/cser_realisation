#ifndef RECSYSTEM_EXTREMALREGION_H
#define RECSYSTEM_EXTREMALREGION_H

#include <common/Rectangle.h>
#include <vector>
#include <common/Point.h>

namespace nprs {

class ExtremalRegion {
public:
    explicit ExtremalRegion(Rectangle const& bounds);

private:
    Rectangle _bounds;
};

}

#endif // RECSYSTEM_EXTREMALREGION_H
