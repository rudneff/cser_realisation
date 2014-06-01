#ifndef COMMON_COLORDATABYTE_H
#define COMMON_COLORDATABYTE_H

#include "ColorData.h"

namespace nprs {

using uchar = unsigned char;

class ColorDataByte : public ColorData {
public:
    ColorDataByte(int width, int height, int numChannels);

    float getValue(int x, int y, int channel) const override;
    float setValue(int x, int y, int channel, float value) const override;

private:
    uchar *_data;
};

}

#endif // COMMON_COLORDATABYTE_H
