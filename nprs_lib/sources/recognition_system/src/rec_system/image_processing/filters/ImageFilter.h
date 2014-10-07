#ifndef RECSYSTEM_IMAGEFILTER_H
#define RECSYSTEM_IMAGEFILTER_H

namespace nprs {

class Image;

class ImageFilter {
public:
    virtual ~ImageFilter() {}
    virtual Image apply(const Image &origin) = 0;
};

}

#endif // RECSYSTEM_IMAGEFILTER_H
