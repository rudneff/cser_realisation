#include "RecognitionSystem.h"
#include "common_structures/RecognitionResults.h"
#include "common_structures/NumberPlate.h"
#include "common_structures/NumberPlateCharacter.h"
#include <rec_system/image_processing/region_detection/cser/CSERDetector.h>
#include "image_processing/region_detection/cser/ExtremalRegion.h"
#include <common/image/ImageConverter.h>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterMNLight.h>
#include <rec_system/image_processing/filters/thresholding/Thresholder.h>
#include <rec_system/machine_learning/DLibDecisionMaker.h>
#include <rec_system/image_processing/object_detection/CascadeObjectDetector.h>
#include <rec_system/image_processing/region_detection/cser/filters/ERFilterMNHeavy.h>

namespace nprs {

typedef dlib::matrix<double> sample_type;
typedef dlib::radial_basis_kernel<sample_type> kernel_type;

RecognitionSystem::RecognitionSystem() {
}

RecognitionSystem::~RecognitionSystem() {
}

RecognitionResults RecognitionSystem::recognize(const Bitmap &image) const {
    sp<DecisionMaker> dm = DLibDecisionMaker<kernel_type>::load("nm_light_trained.dat");
    sp<ERFilterMNLight> lightFilter = std::make_shared<ERFilterMNLight>(dm);
    sp<ERFilterMNHeavy> symbolDetector = std::make_shared<ERFilterMNHeavy>(std::make_shared<CascadeObjectDetector>("cascade.xml"));

//    std::vector<sp<ERFilter>> filters{ std::make_shared<ERFilterEmpty>() };
    std::vector<sp<ERFilter>> filters{ lightFilter, symbolDetector };


    Image converted = ImageConverter::convertRaw(image);

    CSERDetector detector(filters);
    auto results = detector.detect(converted);

    std::vector<sp<NumberPlate>> numberPlates;
    for (auto res : results) {
        sp<NumberPlate> np = std::make_shared<NumberPlate>(std::vector<sp<NumberPlateCharacter>>(), res.bounds());
        numberPlates.push_back(np);
    }

    return std::move(RecognitionResults(std::move(numberPlates), std::move(converted)));
}

}
