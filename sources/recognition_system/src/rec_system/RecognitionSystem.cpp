#include "RecognitionSystem.h"
#include "common_structures/RecognitionResults.h"
#include "common_structures/NumberPlate.h"
#include "common_structures/NumberPlateCharacter.h"
#include "common/Rectangle.h"


namespace nprs {

RecognitionSystem::RecognitionSystem() {

}

RecognitionSystem::~RecognitionSystem() {

}

pRecognitionResults RecognitionSystem::recognize(const Image<float> &image) const {
    std::vector<pNumberPlate> numberPlates = {
        pNumberPlate(new NumberPlate(
        {
            pNumberPlateCharacter(new NumberPlateCharacter('a', Rectangle(10, 10, 20, 20))),
            pNumberPlateCharacter(new NumberPlateCharacter('1', Rectangle(25, 10, 20, 20)))
        },
        Rectangle(10, 10, 90, 20)
        )) 
    };

    return pRecognitionResults(new RecognitionResults(numberPlates));
}

}
