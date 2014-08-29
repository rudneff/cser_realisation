#include "qapplication.h"
#include "qimage.h"
#include <common/NprsStd.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <QDirIterator>
#include <QDebug>
#include <training_lib/SymbolDetectorTrainer.h>
#include <training_lib/input_samples/PositiveImageInputSample.h>
#include <training_lib/input_samples/NegativeImageInputSample.h>
#include <common/image/Bitmap.h>
#include <common/image/Image.h>
#include <common/image/ImageConverter.h>
#include <common/exceptions/NprsException.h>
#include <rec_system/classification/Classifier.h>
#include <training_lib/input_sample_extractors/AutoThresholdExtractor.h>
#include <training_lib/input_sample_extractors/RandomRegionExtractor.h>

static void pushPositiveSamples(const QString &dir, nprs::SymbolDetectorTrainer &trainer);
static void pushNegativeSamples(const QString &dir, nprs::SymbolDetectorTrainer &trainer);
static void showResponses(const nprs::Classifier &classifier, const QString &dir);
static nprs::Image qImageToNprsImage(const QImage &img);
static QImage toQImage(const nprs::Image &img);

int main(int argc, char **argv) {
    try {
        nprs::SymbolDetectorTrainer trainer;
        pushNegativeSamples("training_samples/negative/scene_images", trainer);
        pushPositiveSamples("training_samples/positive", trainer);

        sp<nprs::Classifier> nmLightClassifier = trainer.createNMLightClassifier();
        showResponses(*nmLightClassifier, "training_samples/positive");

        nmLightClassifier->save("out/nm_light_classifier");
    }
    catch (nprs::NprsException &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "press ENTER to continue..";
    std::cin.get();
}

static void pushPositiveSamples(const QString &dir, nprs::SymbolDetectorTrainer &trainer) {
    QDir qdir(dir);
    QDirIterator it(dir, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        QFileInfo fileInfo = it.fileInfo();
        if (fileInfo.isFile()) {
            qDebug() << fileInfo.filePath();
            auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
            nprs::PositiveImageInputSample sample(image);
            
            // debug code
//           {
//                static int c = 0;
//                nprs::AutoThresholdExtractor extractor(sample.image());
//                auto s = extractor.extractNMLightSamples()[0];
//                QString fn = QString::number(c++) + "_";
//                for (float v : s.featureVector()) {
//                    fn += QString::number(v) + "_";
//                }
//
//                toQImage(*s.image()).save("out/pos/" + fn + ".bmp");
//           }

            trainer.pushPositiveSample(sample);
        }
    }
}

static void pushNegativeSamples(const QString &dir, nprs::SymbolDetectorTrainer &trainer) {
    QDirIterator it(dir);
    while (it.hasNext()) {
        it.next();
        QFileInfo fileInfo = it.fileInfo();
        qDebug() << fileInfo.filePath();
        if (fileInfo.isFile()) {
            auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
            nprs::NegativeImageInputSample sample(image, 1, 50, 100);
            trainer.pushNegativeSample(sample);

            // debug code
//            {
//                static int c = 0;
//                nprs::RandomRegionExtractor extractor(sample.image(), 10, 15, 100);
//                auto ss = extractor.extractNMLightSamples();
//
//                for (auto s : ss) {
//                    QString fn = QString::number(c++) + "_";
//                    for (float v : s.featureVector()) {
//                        fn += QString::number(v) + "_";
//                    }
//
//                    toQImage(*s.image()).save("out/neg/" + fn + ".bmp");
//                }
//            }
        }
    }
}

static void showResponses(const nprs::Classifier &classifier, const QString &dir) {
    QDirIterator it(dir);
    while (it.hasNext()) {
        it.next();
        QFileInfo fileInfo = it.fileInfo();
        if (fileInfo.isFile()) {
            auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
            nprs::AutoThresholdExtractor extractor(image);
            auto samples = extractor.extractNMLightSamples();
            std::cout << fileInfo.fileName().toStdString() << " - " << classifier.predict(samples[0].featureVector()) << std::endl;
        }
    }
}

static nprs::Image qImageToNprsImage(const QImage &image) {
    QImage converted = image.convertToFormat(QImage::Format_RGBA8888);
    nprs::Bitmap bmp(converted.bits(), converted.width(), converted.height(), nprs::ColorInfo(nprs::ColorFormat::RGBA, 4));
    
    return nprs::ImageConverter::convertRaw(bmp);
}

static QImage toQImage(const nprs::Image &img) {
    nprs::Bitmap bmp = nprs::ImageConverter::imageToRawBgra(img);
    return QImage(bmp.data(), bmp.width(), bmp.height(), QImage::Format_RGBA8888).copy(0, 0, bmp.width(), bmp.height());
}
