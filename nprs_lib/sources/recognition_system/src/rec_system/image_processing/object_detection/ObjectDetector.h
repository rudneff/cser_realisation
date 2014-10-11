#ifndef RS_OBJECTDETECTOR_H
#define RS_OBJECTDETECTOR_H

#include <vector>

namespace nprs {

class Rectangle;
class Image;

class ObjectDetector {
public:
    virtual std::vector<Rectangle> detect(const Image &image, const Rectangle &bounds) = 0;
};

}

#endif // RS_OBJECTDETECTOR_H
