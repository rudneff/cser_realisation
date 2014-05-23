#ifndef RECSYSTEM_CSERALGORITHM_H
#define RECSYSTEM_CSERALGORITHM_H

#include <common/image/Image.h>
#include <common/Matrix.h>
#include <memory>

namespace nprs {

template <typename T> using pVector = std::shared_ptr<std::vector<T>>;
template <typename T> using pImage = std::shared_ptr<Image<T>>;
class ERDescriptor; using pERDescriptor = std::shared_ptr<ERDescriptor>;
class ERFilter; using pERFilter = std::shared_ptr<ERFilter>;

class CserAlgorithm {
public:
    CserAlgorithm(Image<uchar> const& image, int channel, std::vector<pERFilter> *filters);
    ~CserAlgorithm();

    std::vector<pERDescriptor> perform();

private:
    Image<uchar> const& _image;
    int _channel;
    Matrix<pERDescriptor> _erMap;
    std::vector<pERDescriptor> _descriptors;
};

}

#endif // RECSYSTEM_CSERALGORITHM_H
