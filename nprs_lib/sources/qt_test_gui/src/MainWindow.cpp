#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <rec_system/common_structures/RecognitionResults.h>
#include <rec_system/common_structures/NumberPlate.h>
#include <qpainter.h>
#include <common/image/ImageConverter.h>
#include <qfiledialog.h>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(loadFile()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exit()));
    newFrame(QPixmap("C:\\numplates\\mul.jpg"));
}

void MainWindow::exit() {
    close();
}

MainWindow::~MainWindow() 
{
    delete ui;
}

void MainWindow::newFrame(const QPixmap &pixmap) {
    ui->widget->newFrame(pixmap);
}

void MainWindow::loadFile() {
    using namespace nprs;
    QFileDialog fd;
//    image.convertToFormat(QImage::Format_RGB32);
//    pRecognitionResults results = _recSystem.recognize(image.bits(), image.width(), image.height(), ColorInfo(ColorFormat::RGB, 3));
    newFrame(QPixmap(fd.getOpenFileName()));
}
