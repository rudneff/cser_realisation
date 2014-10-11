#include "ERFilterMNHeavy.h"
#include <rec_system/image_processing/region_detection/cser/ERDescriptor.h>
#include <rec_system/image_processing/object_detection/ObjectDetector.h>
#include <common/image/Image.h>

namespace nprs {

ERFilterMNHeavy::ERFilterMNHeavy(sp<ObjectDetector> const& symbolDetector)
: _symbolDetector(symbolDetector)
{
}

std::vector<ERDescriptor*> ERFilterMNHeavy::perform(std::vector<ERDescriptor*> const& regions, Image const& image) {
    std::vector<ERDescriptor*> result;

    for (ERDescriptor *region : regions) {
        Rectangle bounds = region->bounds();
        std::vector<Rectangle> detected = _symbolDetector->detect(image, bounds);
        if (detected.size() > 0) {
            result.push_back(region);
        }
    }

    return result;
}

}
