#ifndef RECSYSTEM_OTSUTHRESHOLDER_H
#define RECSYSTEM_OTSUTHRESHOLDER_H

#include <vector>

namespace nprs {

class Image;

class OtsuThresholder {
public:
    float findThreshold(const Image &image, int channel = 0);

private:
    double px(int init, int end, const std::vector<float> &hist);
    double mx(int init, int end, const std::vector<float> &hist);
    int findMaxIndex(const std::vector<float> &vec);
    std::vector<float> histogram(const Image &image, int channel);
};

}

#endif // RECSYSTEM_OTSUTHRESHOLDER_H

