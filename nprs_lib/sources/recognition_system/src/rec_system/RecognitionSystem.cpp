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
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterEmpty.h>

#include <chrono>
#include <iostream>
#include <rec_system/image_processing/filters/thresholding/Thresholder.h>

namespace nprs {

RecognitionSystem::RecognitionSystem() {
    
}

RecognitionSystem::~RecognitionSystem() {
    
}

RecognitionResults RecognitionSystem::recognize(const Bitmap &image) const {
    std::vector<pERFilter> filters{ pERFilter(new ERFilterMNLight()) };
    Image converted = ImageConverter::convertRaw(image);

    CSERDetector detector(filters);
    auto results = detector.detect(converted);

    std::vector<pNumberPlate> numberPlates;
     for (auto res : results) {
         pNumberPlate np = pNumberPlate(new NumberPlate(std::vector<pNumberPlateCharacter>(), res.bounds()));
         numberPlates.push_back(np); 
     }

    return std::move(RecognitionResults(std::move(numberPlates), std::move(converted)));
}

}
