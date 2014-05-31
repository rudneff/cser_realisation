#include "Color.h"

nprs::ColorInfo nprs::ColorInfo::RgbByte255() {
    return ColorInfo(ColorFormat::RGB255, 3, 3);
}

nprs::ColorInfo nprs::ColorInfo::BgraByte255() {
    return ColorInfo(ColorFormat::BGRA255, 4, 4);
}
