#include "RecognitionSystem.h"
#include "common_structures/RecognitionResults.h"
#include "common_structures/NumberPlate.h"
#include "common_structures/NumberPlateCharacter.h"
#include "common/Rectangle.h"
#include <rec_system/image_processing/region_detection/cser/CSERDetector.h>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterConditional.h>
#include <rec_system/image_processing/region_detection/cser/ERDescriptor.h>
#include "image_processing/region_detection/cser/ExtremalRegion.h"
#include <common/image/ImageConverter.h>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterMNLight.h>

namespace nprs {

using pERFilterConditional = std::shared_ptr<ERFilterConditional>;

RecognitionSystem::RecognitionSystem() {
    
}

RecognitionSystem::~RecognitionSystem() {
    
}

pRecognitionResults RecognitionSystem::recognize(const uchar *data, int width, int height, ColorInfo cf) const {
    std::vector<pERFilter> filters;
    filters.push_back(pERFilter(new ERFilterMNLight()));

    Image converted = ImageConverter::convertRaw(data, width, height, cf.format());

    CSERDetector detector(filters);
    auto results = detector.detect(converted);
    
    std::vector<pNumberPlate> numberPlates;
    for (auto res : results) {
        pNumberPlate np = pNumberPlate(new NumberPlate(std::vector<pNumberPlateCharacter>(), res.getBounds()));
        numberPlates.push_back(np);
    }

    for (auto res: results) {
    }

    return pRecognitionResults(new RecognitionResults(numberPlates, converted));
}

}
