#ifndef RECSYSTEM_IMAGEFILTER_H
#define RECSYSTEM_IMAGEFILTER_H

namespace nprs {

class Image;

class ImageFilter {
public:
    virtual ~ImageFilter() {}

    Image apply(const Image &origin);
    Image apply(const Image &origin, int channel);

    virtual void applyChannel(Image &outImage, int outChannel, const Image &inImage, int inChannel) = 0;
};

}

#endif // RECSYSTEM_IMAGEFILTER_H
