#ifndef RECSYSTEM_ERFILTER_HEAVY
#define RECSYSTEM_ERFILTER_HEAVY

#include <common/NprsStd.h>
#include <rec_system/image_processing/region_detection/cser/ERFilter.h>

namespace nprs {

class Image;
class ObjectDetector;

class ERFilterMNHeavy : public ERFilter {
public:
    ERFilterMNHeavy(sp<ObjectDetector> const& symbolDetector);

    std::vector<ERDescriptor*> perform(const std::vector<ERDescriptor*> &regions, Image const& image) override;

private:
    sp<ObjectDetector> _symbolDetector;
};

}

#endif // RECSYSTEM_ERFILTER_HEAVY
