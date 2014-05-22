#ifndef RECSYSTEM_EXTREMALREGION_H
#define RECSYSTEM_EXTREMALREGION_H

#include <common/Rectangle.h>
#include <vector>
#include <common/Point.h>
#include <rec_system/image_processing/region_detection/cser/ERDescriptor.h>

namespace nprs {

class ExtremalRegion {
public:
    explicit ExtremalRegion(Rectangle const& bounds);

    Rectangle bounds() { return _bounds; }

private:
    Rectangle _bounds;
};

}

#endif // RECSYSTEM_EXTREMALREGION_H
