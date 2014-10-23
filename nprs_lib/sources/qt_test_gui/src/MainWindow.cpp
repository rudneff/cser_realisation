#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <rec_system/common_structures/RecognitionResults.h>
#include <rec_system/common_structures/NumberPlate.h>
#include <rec_system/common_structures/NumberPlateCharacter.h>
#include <common/Rectangle.h>
#include <qpainter.h>
#include <common/image/ImageConverter.h>
#include <qfiledialog.h>
#include <qdebug.h>
#include <qpainter.h>
#include <chrono>
#include <future>
#include <rec_system/image_processing/SobelOperator.h>
#include <rec_system/image_processing/SimpleGradientOperator.h>
#include <random>

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
    result.save("test.bmp", "bmp", 100);

    painter.begin(&result);

    std::default_random_engine e(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> colorDist(0, 255);

    for (sp<NumberPlate> np : results.numberPlates()) {
        painter.setPen(QPen(QColor::fromRgb(colorDist(e), colorDist(e), colorDist(e))));

        nprs::Quad bounds = np->bounds();
        QPolygon qPolygon(4);
        qPolygon.setPoint(0, bounds.p1().x(), bounds.p1().y());
        qPolygon.setPoint(1, bounds.p2().x(), bounds.p2().y());
        qPolygon.setPoint(2, bounds.p3().x(), bounds.p3().y());
        qPolygon.setPoint(3, bounds.p4().x(), bounds.p4().y());
        qPolygon.setPoint(3, bounds.p1().x(), bounds.p1().y());

//        painter.setPen(QPen(QColor::fromRgb(255, 0, 0)));
//        painter.drawPolygon(qPolygon);

        for (sp<NumberPlateCharacter> npch: np->characters()) {
            painter.drawRect(npch->bounds().x(), npch->bounds().y(), npch->bounds().width(), npch->bounds().height());
        }

//        painter.setPen(QPen(QColor::fromRgb(0, 255, 0)));
        painter.drawLine(np->line().x0(), np->line().y0(), np->line().x1(), np->line().y1());
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
