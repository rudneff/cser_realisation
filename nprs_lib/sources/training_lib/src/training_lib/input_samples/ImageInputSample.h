#ifndef TRAININGLIB_IMAGEINPUTSAMPLE_H
#define TRAININGLIB_IMAGEINPUTSAMPLE_H

#include <common/NprsStd.h>
#include <training_lib/InputSample.h>

namespace nprs {

class Image;

class ImageInputSample : public InputSample {
public:
    ImageInputSample(sp<const Image> image);

    sp<const Image> image() const { return _image; }

private:
    sp<const Image> _image;
};

}

#endif // TRAININGLIB_IMAGEINPUTSAMPLE_H
