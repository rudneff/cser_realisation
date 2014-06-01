#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <rec_system/common_structures/RecognitionResults.h>
#include <rec_system/common_structures/NumberPlate.h>
#include <qpainter.h>
#include <common/image/ImageConverter.h>
#include <qfiledialog.h>
#include <qdebug.h>
#include <qpainter.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(loadFile()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exit()));
    newFrame(QImage("C:\\numplates\\mul.jpg"));
}

void MainWindow::exit() {
    close();
}

MainWindow::~MainWindow() 
{
    delete ui;
}

void MainWindow::newFrame(const QImage &frame) {
    using namespace nprs;
    QImage image = frame.convertToFormat(QImage::Format_RGB888);
    pRecognitionResults results = _recSystem.recognize(image.bits(), image.width(), image.height(), ColorInfo(ColorFormat::RGB, 3));
    QPainter painter;
    std::vector<uchar> data = ImageConverter::imageToRawRgb(results->resultImage());
    QImage result(&data[0], results->resultImage().width(), results->resultImage().height(), QImage::Format_RGB888);
    painter.begin(&result);
    for (pNumberPlate np : results->numberPlates()) {
        nprs::Rectangle bounds = np->bounds();
        if (bounds.width() > 5 && bounds.height() > 7) {
            painter.drawRect(bounds.x(), bounds.y(), bounds.width(), bounds.height());
        }
    }
    painter.end();
    ui->widget->newFrame(QPixmap::fromImage(result));
}

void MainWindow::loadFile() {
    using namespace nprs;
    QFileDialog fd;
    QImage frame(fd.getOpenFileName());
    newFrame(frame);
}
