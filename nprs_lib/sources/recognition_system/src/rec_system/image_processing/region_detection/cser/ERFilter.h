#ifndef RECSYSTEM_ERFILTER
#define RECSYSTEM_ERFILTER

namespace nprs {

class ERDescriptor;

class ERFilter {
public:
    virtual ~ERFilter() {}
    virtual bool isRegion(const ERDescriptor &region) = 0;
};

}

#endif // RECSYSTEM_ERFILTER
