#ifndef RECSYSTEM_RECOGNITIONRESULTS_H
#define RECSYSTEM_RECOGNITIONRESULTS_H

#include <common/NprsStd.h>
#include <vector>
#include <memory>
#include <common/image/Image.h>

namespace nprs {

class NumberPlate;

class RecognitionResults {
public:
    RecognitionResults(const std::vector<sp<NumberPlate>> &numberPlates, const Image &resultImage);
    RecognitionResults(std::vector<sp<NumberPlate>> && numberPlates, Image && resultImage);

    RecognitionResults(RecognitionResults && other);
    RecognitionResults& operator= (RecognitionResults && other);

    const std::vector<sp<NumberPlate>>& numberPlates() const { return _numberPlates; }
    const Image & resultImage() const { return _resultImage; }

private:
    std::vector<sp<NumberPlate>> _numberPlates;
    Image _resultImage;
};

}

#endif
