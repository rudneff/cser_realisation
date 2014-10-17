#ifndef RECSYSTEM_ERFILTER_HEAVY
#define RECSYSTEM_ERFILTER_HEAVY

#include <common/NprsStd.h>
#include <rec_system/image_processing/region_detection/cser/ERFilter.h>

namespace nprs {

class Image;
class DecisionMaker;
class FeatureExtractor;

class ERFilterMNHeavy : public ERFilter {
public:
    ERFilterMNHeavy(sp<DecisionMaker> const& classifier, sp<FeatureExtractor> const& featureExtractor);

    std::vector<ERDescriptor*> perform(const std::vector<ERDescriptor*> &regions, Image const& image) override;

private:
    sp<DecisionMaker> _classifier;
    sp<FeatureExtractor> _featureExtractor;
};

}

#endif // RECSYSTEM_ERFILTER_HEAVY
