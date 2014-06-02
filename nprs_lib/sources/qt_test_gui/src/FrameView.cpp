#include "FrameView.h"
#include <QPaintEvent>
#include <qpainter.h>
#include <qpaintengine.h>

FrameView::FrameView(QWidget *parent) 
    : QWidget(parent)
{
}

void FrameView::paintEvent(QPaintEvent* e) {
    QPainter painter;
    painter.begin(this);
    QPixmap scaled = QPixmap::fromImage(_frame).scaled(width(), height(), Qt::KeepAspectRatio);
    painter.drawPixmap((width() - scaled.width()) / 2, 0, scaled);
}

void FrameView::newFrame(const QImage &frame) {
    _frame = frame;
    update();
}
