#ifndef RECOGNITION_SYSTEM_H
#define RECOGNITION_SYSTEM_H

#include <memory>
#include <vector>

using uchar = unsigned char;

namespace nprs {

class Bitmap;
class RecognitionResults;

class RecognitionSystem {
public: 
    RecognitionSystem();
    ~RecognitionSystem();

    RecognitionResults recognize(const Bitmap &image) const;
};

}

#endif