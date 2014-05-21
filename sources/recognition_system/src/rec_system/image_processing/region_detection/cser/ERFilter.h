#ifndef RECSYSTEM_ERFILTER
#define RECSYSTEM_ERFILTER

namespace nprs {

class ExtremalRegion;

class ERFilter {
public:
    virtual ~ERFilter() {}
    virtual bool isRegion(const ExtremalRegion &region) = 0;
};

}

#endif // RECSYSTEM_ERFILTER
