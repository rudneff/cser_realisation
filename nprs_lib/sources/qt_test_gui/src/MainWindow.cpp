#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <rec_system/common_structures/RecognitionResults.h>
#include <rec_system/common_structures/NumberPlate.h>
#include <qpainter.h>
#include <common/image/ImageConverter.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(loadFile()));
}

MainWindow::~MainWindow() 
{
    delete ui;
}

void MainWindow::newFrame(const QPixmap &pixmap) {
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(pixmap);
    ui->graphicsView->setScene(scene);
}

void MainWindow::loadFile() {
    using namespace nprs;
    QImage image("C:\\numplates\\mul.jpg");
//    image.convertToFormat(QImage::Format_RGB32);
//    pRecognitionResults results = _recSystem.recognize(image.bits(), image.width(), image.height(), ColorInfo(ColorFormat::RGB, 3));
    newFrame(QPixmap::fromImage(image));
}
