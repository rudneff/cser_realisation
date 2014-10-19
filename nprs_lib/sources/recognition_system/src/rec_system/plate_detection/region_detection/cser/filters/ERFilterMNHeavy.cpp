#include "ERFilterMNHeavy.h"
#include <rec_system/plate_detection/region_detection/cser/ERDescriptor.h>
#include <rec_system/machine_learning/DecisionMaker.h>
#include <common/image/Image.h>
#include <rec_system/image_processing/feature_extraction/HogFeatureExtractor.h>
#include <iostream>

namespace nprs {

ERFilterMNHeavy::ERFilterMNHeavy(sp<DecisionMaker> const& classifier, sp<FeatureExtractor> const& featureExtractor)
: _classifier(classifier), _featureExtractor(featureExtractor)
{
}

std::vector<ERDescriptor*> ERFilterMNHeavy::perform(std::vector<ERDescriptor*> const& regions, Image const& image) {
    std::cout << regions.size() << std::endl;

    std::vector<ERDescriptor*> result;

    for (ERDescriptor *region : regions) {
        if (region->bounds().area() > 25) {
            auto features = _featureExtractor->extract(image, 0, region->bounds());
            float value = (*_classifier)(features);
//            std::cout << value << std::endl;
            if (value > 0.5)
                result.push_back(region);
        }
    }

    std::cout << result.size() << std::endl;
    return result;
}

}
