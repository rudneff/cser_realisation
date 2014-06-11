#include "qapplication.h"
#include "qimage.h"

#include <sstream>
#include <iostream>
#include <training_lib/SampleExtractor.h>
#include <common/image/Bitmap.h>
#include <rec_system/image_processing/region_detection/cser/ExtremalRegion.h>
#include <common/image/ImageConverter.h>
#include <common/exceptions/ArgumentException.h>
#include <training_lib/Sample.h>

int main(int argc, char **argv) {
    std::string fileName(argv[1]); 
    QImage image = QImage(fileName.c_str()).convertToFormat(QImage::Format_RGB888);

    nprs::SampleExtractor extractor;
    nprs::Bitmap bmp(image.bits(), image.width(), image.height(), nprs::ColorInfo(nprs::ColorFormat::RGB, 3));

    auto res = extractor.extractPositiveSample(bmp);
    for (auto sample : res) {
        try {
            nprs::Bitmap bmp = nprs::ImageConverter::imageToRawRgb(sample.image());
            QImage qImg(bmp.data(), bmp.width(), bmp.height(), QImage::Format_RGB888);
            std::ostringstream fns;
            fns << "out/" << sample.region().threshold() << ".bmp";
            qImg.save(fns.str().c_str());
            std::cout << fns.str() << std::endl;
        } catch(nprs::ArgumentException &e) {
            std::cout << e.getMessage() << std::endl;
        }
    }
}
