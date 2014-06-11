#include "RecognitionResults.h"
#include <iostream>

using namespace nprs;

RecognitionResults::RecognitionResults(std::vector<pNumberPlate> const& numberPlates, const Image &resultImage) 
    : _numberPlates(numberPlates), _resultImage(resultImage) 
{
}

RecognitionResults::RecognitionResults(std::vector<pNumberPlate> && numberPlates, Image && resultImage) 
    : _numberPlates(std::move(numberPlates)), _resultImage(std::move(resultImage))
{
}

RecognitionResults::RecognitionResults(RecognitionResults && other) 
    : _numberPlates(std::move(other._numberPlates)), _resultImage(std::move(other._resultImage))
{
}

RecognitionResults& RecognitionResults::operator=(RecognitionResults && other) {
    if (this != &other) {
        _numberPlates = std::move(other._numberPlates);
        _resultImage = std::move(other._resultImage);
    }
    return *this;
}
