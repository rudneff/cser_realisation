#ifndef RECSYSTEM_RECOGNITIONRESULTS_H
#define RECSYSTEM_RECOGNITIONRESULTS_H

#include <vector>
#include <memory>
#include <common/image/Image.h>

namespace nprs {

class NumberPlate; using pNumberPlate = std::shared_ptr<NumberPlate>;

class RecognitionResults {
public:
    RecognitionResults(const std::vector<pNumberPlate> &numberPlates, const Image resultImage)
            : _numberPlates(numberPlates), _resultImage(resultImage)
    {}

    const std::vector<pNumberPlate>& numberPlates() const { return _numberPlates; }
    const Image & resultImage() const { return _resultImage; }

private:
    std::vector<pNumberPlate> _numberPlates;
    Image _resultImage;
};

}

#endif
