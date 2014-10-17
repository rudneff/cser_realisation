#ifndef RS_SIMPLEGRADIENTOPERATOR_H
#define RS_SIMPLEGRADIENTOPERATOR_H

#include <common/image/Image.h>
#include "GradientOperator.h"

namespace nprs {

class SimpleGradientOperator: public GradientOperator {
public:
    Image perform(const Image &inputImage, int channel, const Rectangle &bounds) const override;
};

}

#endif // RS_SIMPLEGRADIENTOPERATOR_H
