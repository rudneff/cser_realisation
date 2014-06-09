#ifndef RECOGNITION_SYSTEM_H
#define RECOGNITION_SYSTEM_H

#include <memory>
#include <vector>
#include <common/image/Image.h>

using uchar = unsigned char;

namespace nprs {

class RawImageData;
class RecognitionResults;

class RecognitionSystem {
public: 
    RecognitionSystem();
    ~RecognitionSystem();

    RecognitionResults recognize(const RawImageData &image) const;
};

}

#endif