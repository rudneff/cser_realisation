#ifndef TRAININGLIB_SAMPLE_H
#define TRAININGLIB_SAMPLE_H

#include <rec_system/image_processing/region_detection/cser/ExtremalRegion.h>
#include <common/image/Image.h>

namespace nprs {

class Sample final {
public:
    Sample(const ExtremalRegion &region, const Image &image);

    const ExtremalRegion & region() { return _region; }
    const Image & image() { return _image; }

private:
    ExtremalRegion _region;
    Image _image;
};

#include "Sample.inl"

}

#endif // TRAININGLIB_SAMPLE_H
