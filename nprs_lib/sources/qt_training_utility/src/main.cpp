#include "qapplication.h"
#include "qimage.h"

#include <common/NprsStd.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <training_lib/SampleExtractor.h>
#include <common/image/Bitmap.h>
#include <rec_system/image_processing/region_detection/cser/ExtremalRegion.h>
#include <common/image/ImageConverter.h>
#include <common/exceptions/ArgumentException.h>
#include <training_lib/Sample.h>
#include <training_lib/input_sample_extractors/AutoThresholdExtractor.h>
#include <training_lib/input_sample_extractors/RandomRegionExtractor.h>

void printVec(std::vector<float> const& vec) {
    std::cout << "[";
    for (float f : vec) {
        std::cout << " " << f;
    }
    std::cout << "]";
}

int main(int argc, char **argv) {
    std::string fileName(argv[1]);
    QImage image = QImage(fileName.c_str()).convertToFormat(QImage::Format_RGB888);
    
    nprs::Bitmap bmp(image.bits(), image.width(), image.height(), nprs::ColorInfo(nprs::ColorFormat::RGB, 3));
    auto img = make_shared<nprs::Image>(nprs::ImageConverter::convertRaw(bmp));
    nprs::AutoThresholdExtractor extractor(img);

    auto samples = extractor.extractNMLightSamples();
    int counter = 0;
    for (auto sample : samples) {
        printVec(sample.featureVector());
        std::cout << std::endl;
        nprs::Bitmap regBmp = nprs::ImageConverter::imageToRawRgb(*sample.image());
        QImage resImage(regBmp.data(), regBmp.width(), regBmp.height(), QImage::Format_RGB888);
        resImage.save("out/" + QString::number(counter++) + ".bmp", "bmp", 100);
    }

    std::cin.get();
}
