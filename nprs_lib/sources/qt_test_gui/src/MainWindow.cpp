#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <rec_system/common_structures/RecognitionResults.h>
#include <rec_system/common_structures/NumberPlate.h>
#include <qpainter.h>
#include <common/image/ImageConverter.h>
#include <qfiledialog.h>
#include <qdebug.h>
#include <qpainter.h>
#include <chrono>
#include <future>
#include <rec_system/image_processing/SobelOperator.h>
#include <rec_system/image_processing/SimpleGradientOperator.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(loadFile()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exit()));
    connect(ui->actionRecognize, SIGNAL(triggered()), this, SLOT(recognize()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(recognize()));
    connect(ui->pushButton_2, SIGNAL(clicked), this, SLOT(loadFile()));
    newFrame(QImage("/Users/vardan/Pictures/cars/images00013.png"));
}

void MainWindow::recognize() {
    performRecognition(ui->widget->frame());
    //testSobel(ui->widget->frame());
    //testResize(ui->widget->frame());
}

void MainWindow::performRecognition(QImage& frame) {
    using namespace nprs;

    Bitmap rawImage(frame.bits(), frame.width(), frame.height(), ColorInfo(ColorFormat::RGB, 3));
    auto before = std::chrono::high_resolution_clock::now();
    RecognitionResults results = _recSystem.recognize(rawImage);
    auto after = std::chrono::high_resolution_clock::now();
    
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(after - before);

    qDebug() << "recognition took " << ms.count() << " ms";

    QPainter painter;
    nprs::Bitmap resultImage = ImageConverter::imageToRawRgb(results.resultImage());
    QImage result = QImage(resultImage.data(), resultImage.width(), resultImage.height(), QImage::Format_RGB888).copy();
    painter.begin(&result);
    painter.setPen(QPen(QColor::fromRgb(255, 0, 0)));
    for (sp<NumberPlate> np : results.numberPlates()) {
        nprs::Rectangle bounds = np->bounds();
        painter.drawRect(bounds.x(), bounds.y(), bounds.width(), bounds.height());
    }
    painter.end();
    ui->widget->newFrame(result.copy());
}

void MainWindow::testSobel(QImage& frame) {
    using namespace nprs;

    Bitmap rawImage(frame.bits(), frame.width(), frame.height(), nprs::ColorInfo(nprs::ColorFormat::RGB, 3));
    Image image = ImageConverter::convertRaw(rawImage);
    SobelOperator sobel;
    Image gradients = sobel.perform(image, 2, Rectangle(0, 0, image.width(), image.height())).copyChannel(2);
    Bitmap resultRaw = ImageConverter::imageToRawRgb(gradients);

    QImage resultImage = QImage(resultRaw.data(), resultRaw.width(), resultRaw.height(), QImage::Format_RGB888).copy();
    ui->widget->newFrame(resultImage);
}

void MainWindow::testResize(QImage &frame) {
    using namespace nprs;

    Bitmap rawImage(frame.bits(), frame.width(), frame.height(), nprs::ColorInfo(nprs::ColorFormat::RGB, 3));
    Image image = ImageConverter::convertRaw(rawImage);
    Bitmap resultRaw = ImageConverter::imageToRawRgb(image.resized(100, 100));
    QImage resultImage = QImage(resultRaw.data(), resultRaw.width(), resultRaw.height(), QImage::Format_RGB888).copy();
    ui->widget->newFrame(resultImage);
}


void MainWindow::exit() {
    close();
}

MainWindow::~MainWindow()  {
    delete ui;
}

void MainWindow::newFrame(const QImage &frame) {
    ui->widget->newFrame(frame.convertToFormat(QImage::Format_RGB888));
}

void MainWindow::loadFile() {
    using namespace nprs;
    QFileDialog fd;
    QImage frame(fd.getOpenFileName());
    newFrame(frame);
}

void MainWindow::on_pushButton_2_clicked() {
    loadFile();
}
