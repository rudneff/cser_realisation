#include "mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(loadFile()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exit()));
    connect(ui->actionRecognize, SIGNAL(triggered()), this, SLOT(recognize()));
    newFrame(QImage("C:/Users/vardan/Desktop/cars/images00067.png"));
}

void MainWindow::recognize() {
    performRecognition(ui->widget->frame());
}

void MainWindow::performRecognition(QImage& frame) {
    using namespace nprs;

    RawImageData rawImage(frame.bits(), frame.width(), frame.height(), ColorInfo(ColorFormat::RGB, 3));
    auto before = std::chrono::high_resolution_clock::now();
    RecognitionResults results = _recSystem.recognize(rawImage);
    auto after = std::chrono::high_resolution_clock::now();
    
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(after - before);

    qDebug() << "recognition took " << ms.count() << " ms";

    QPainter painter;
    std::vector<uchar> data = ImageConverter::imageToRawRgb(results.resultImage());
    QImage result(&data[0], results.resultImage().width(), results.resultImage().height(), QImage::Format_RGB888);
    painter.begin(&result);
    painter.setPen(QPen(QColor::fromRgb(255, 0, 0)));
    for (pNumberPlate np : results.numberPlates()) {
        nprs::Rectangle bounds = np->bounds();
        painter.drawRect(bounds.x(), bounds.y(), bounds.width(), bounds.height());
    }
    painter.end();
    ui->widget->newFrame(result.copy());
}

void MainWindow::exit() {
    close();
}

MainWindow::~MainWindow() 
{
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
