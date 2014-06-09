#ifndef RECSYSTEM_EXTREMALREGION_H
#define RECSYSTEM_EXTREMALREGION_H

#include <common/Rectangle.h>
#include <vector>
#include <common/Point.h>

namespace nprs {

class ERDescriptor;

class ExtremalRegion {
public:
    explicit ExtremalRegion(const Rectangle &bounds);
    explicit ExtremalRegion(const ERDescriptor *erd);

    const Rectangle & getBounds() { return _bounds; }

private:
    Rectangle _bounds;
};

}

#endif // RECSYSTEM_EXTREMALREGION_H
