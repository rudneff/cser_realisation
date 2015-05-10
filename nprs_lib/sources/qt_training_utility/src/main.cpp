#include "qapplication.h"
#include "qimage.h"
#include <common/NprsStd.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <QDirIterator>
#include <QDebug>
#include <training_lib/Sample.h>
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
#include <functional>
#include <rec_system/machine_learning/DecisionMaker.h>
#include <rec_system/machine_learning/Trainer.h>
#include <training_lib/input_sample_extractors/LightRandomRegionExtractor.h>
#include <training_lib/input_sample_extractors/HogSampleExtractor.h>
#include <training_lib/input_sample_extractors/HeavyRandomRegionExtractor.h>

static void pushPositiveSamples(const QString &dir, nprs::SymbolDetectorTrainer &trainer);
static void pushNegativeSamples(const QString &dir, nprs::SymbolDetectorTrainer &trainer);
static void showResponses(const nprs::DecisionMaker &classifier, const QString &dir, nprs::DecisionMaker const &heavyClassifier);
static void showNegativeResponses(const nprs::DecisionMaker &classifier, const nprs::DecisionMaker &heavyClassifier, const QString &dir);
static void performOnImages(const QString &dir, std::function<void(const QFileInfo &)> func);
static nprs::Image qImageToNprsImage(const QImage &img);
static QImage toQImage(const nprs::Image &img);

int main(int argc, char **argv) {
    try {
        nprs::SymbolDetectorTrainer trainer;
        pushNegativeSamples("training_samples/negative/scene_images", trainer);
        pushPositiveSamples("training_samples/positive", trainer);

        auto nmLightClassifier = trainer.createNMLightClassifier();
        auto heavyClassifier = trainer.createNMHeavyClassifier();

        showNegativeResponses(*nmLightClassifier, *heavyClassifier, "training_samples/negative/scene_images");
        showResponses(*nmLightClassifier, "training_samples/positive", *heavyClassifier);

        nmLightClassifier->serialize("nm_light_trained.dat");
        heavyClassifier->serialize("nm_heavy_trained.dat");
    }
    catch (nprs::NprsException &e) {
        std::cout << e.what() << std::endl;
    }

//    std::cout << "press ENTER to continue..";
//    std::cin.get();
}

static void pushPositiveSamples(const QString &dir, nprs::SymbolDetectorTrainer &trainer) {
    performOnImages(dir,[&] (const QFileInfo &fileInfo) {
        qDebug() << fileInfo.filePath();
        auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
        nprs::PositiveImageInputSample sample(image);

        trainer.pushNMLightPositiveSample(sample);
    });

    performOnImages(dir,[&] (const QFileInfo &fileInfo) {
        qDebug() << fileInfo.filePath();
        auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
        nprs::PositiveImageInputSample sample(image);

        trainer.pushNMHeavyPositiveSample(sample);
    });
}

static void pushNegativeSamples(const QString &dir, nprs::SymbolDetectorTrainer &trainer) {
    performOnImages(dir, [&] (const QFileInfo &fileInfo) {
        qDebug() << fileInfo.filePath();
        auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
        nprs::NegativeImageInputSample sample(image, 10, 5, 100);
        trainer.pushNMLightNegativeSample(sample);
    });

    performOnImages(dir, [&] (const QFileInfo &fileInfo) {
        qDebug() <<  fileInfo.filePath();
        auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
        nprs::NegativeImageInputSample sample(image, 20, 5, 15);
        trainer.pushNMHeavyNegativeSample(sample);
    });

//    performOnImages(dir, [&] (const QFileInfo &fileInfo) {
//        qDebug() <<  fileInfo.filePath();
//        auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
//        nprs::NegativeImageInputSample sample(image, 15, 10, 50);
//        trainer.pushNMHeavyNegativeSample(sample);
//    });

//    performOnImages(dir, [&] (const QFileInfo &fileInfo) {
//        qDebug() <<  fileInfo.filePath();
//        auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
//        nprs::NegativeImageInputSample sample(image, 10, 50, 150);
//        trainer.pushNMHeavyNegativeSample(sample);
//    });
}

//static void createNegativeSamples(const QString &dir) {
//    performOnImages(
//        dir,
//        [&] (const QFileInfo &fileInfo) {
//            auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
//            nprs::HeavyRandomRegionExtractor extractor(image, 15, 5, 50);
//        }
//    );
//}

static void showResponses(const nprs::DecisionMaker &classifier, const QString &dir, nprs::DecisionMaker const &heavyClassifier) {
    performOnImages(dir, [&] (const QFileInfo& fileInfo) {
        auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
        nprs::AutoThresholdExtractor extractor(image);
        nprs::HogSampleExtractor heavyExtractor(image);

        auto samples = extractor.extractSamples();
        auto heavySamples = heavyExtractor.extractSamples();

        std::cout << fileInfo.fileName().toStdString() <<
            " - " << classifier(samples[0].featureVector())
            << " - " << heavyClassifier(heavySamples[0].featureVector()) << std::endl;
    });
}

static void showNegativeResponses(const nprs::DecisionMaker &classifier, const nprs::DecisionMaker &heavyClassifier, const QString &dir) {
    performOnImages(dir, [&] (const QFileInfo& fileInfo) {
        auto image = std::make_shared<nprs::Image>(qImageToNprsImage(QImage(fileInfo.filePath())));
        nprs::LightRandomRegionExtractor extractor(image, 15, 5, 50);
        nprs::HeavyRandomRegionExtractor heavyExtractor(image, 5, 5, 50);
        auto samples = extractor.extractSamples();
        auto heavySamples = heavyExtractor.extractSamples();

        std::cout << fileInfo.fileName().toStdString() << ": " << classifier(samples[0].featureVector())
            << " - " << heavyClassifier(heavySamples[0].featureVector()) << std::endl;
    });
}

static void performOnImages(const QString &dir, std::function<void(const QFileInfo &)> func) {
    QDirIterator it(dir);
    while (it.hasNext()) {
        it.next();
        if (it.fileInfo().fileName().endsWith(".png") || it.fileInfo().fileName().endsWith(".jpg")) {
            func(it.fileInfo());
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
