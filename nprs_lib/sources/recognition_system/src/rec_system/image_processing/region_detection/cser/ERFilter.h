#ifndef RECSYSTEM_ERFILTER
#define RECSYSTEM_ERFILTER

#include <vector>

namespace nprs {

class ERDescriptor;
class Image;

class ERFilter {
public:
    virtual ~ERFilter() {};
    virtual std::vector<ERDescriptor *> perform(const std::vector<ERDescriptor *> &regions, Image const &image) = 0;
};

}

#endif // RECSYSTEM_ERFILTER
