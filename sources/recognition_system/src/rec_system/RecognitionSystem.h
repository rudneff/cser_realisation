#ifndef RECOGNITION_SYSTEM_H
#define RECOGNITION_SYSTEM_H

#include <memory>
#include <vector>
#include <common/image/Image.h>

using uchar = unsigned char;

namespace nprs {

class RecognitionResults; using pRecognitionResults = std::shared_ptr<RecognitionResults>;

class RecognitionSystem {
public:
    RecognitionSystem();
    ~RecognitionSystem();

    pRecognitionResults recognize(const Image<uchar> &image) const;
};

}

#endif