#include "RecognitionSystem.h"
#include "common_structures/RecognitionResults.h"
#include "common_structures/NumberPlate.h"
#include "common_structures/NumberPlateCharacter.h"
#include <rec_system/plate_detection/region_detection/cser/CSERDetector.h>
#include <rec_system/plate_detection/region_detection/cser/ExtremalRegion.h>
#include <common/image/ImageConverter.h>
#include <rec_system/plate_detection/region_detection/cser/filters/ERFilterMNLight.h>
#include <rec_system/image_processing/filters/thresholding/Thresholder.h>
#include <rec_system/machine_learning/DLibDecisionMaker.h>
#include <rec_system/image_processing/object_detection/CascadeObjectDetector.h>
#include <rec_system/plate_detection/region_detection/cser/filters/ERFilterMNHeavy.h>
#include <rec_system/image_processing/feature_extraction/HogFeatureExtractor.h>
#include <rec_system/plate_detection/PlateDetector.h>

namespace nprs {

typedef dlib::matrix<double> sample_type;
typedef dlib::radial_basis_kernel<sample_type> kernel_type;

RecognitionSystem::RecognitionSystem() {
}

RecognitionSystem::~RecognitionSystem() {
}

RecognitionResults RecognitionSystem::recognize(const Bitmap &image) const {
    sp<DecisionMaker> dm = DLibDecisionMaker<kernel_type>::load("good_classifiers/nm_light_trained_171014.dat");
    sp<ERFilterMNLight> lightFilter = std::make_shared<ERFilterMNLight>(dm);
    sp<ERFilterMNHeavy> heavyFilter = std::make_shared<ERFilterMNHeavy>(
        DLibDecisionMaker<kernel_type>::load("good_classifiers/nm_heavy_trained_171014.dat"),
        std::make_shared<HogFeatureExtractor>());

//    std::vector<sp<ERFilter>> filters{ std::make_shared<ERFilterEmpty>() };
    std::vector<sp<ERFilter>> filters{ lightFilter, heavyFilter };

    Image converted = ImageConverter::convertRaw(image);

    CSERDetector detector(filters);
    auto symbols = detector.detect(converted);

    PlateDetector plateDetector;
    auto numberPlates = plateDetector.detectPlate(symbols);

    return RecognitionResults(numberPlates, converted);
}

}
