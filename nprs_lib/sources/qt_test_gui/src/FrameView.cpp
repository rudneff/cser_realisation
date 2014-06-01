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
    QPixmap scaled = _pixMap.scaled(width(), height(), Qt::KeepAspectRatioByExpanding);
    painter.drawPixmap((width() - scaled.width()) / 2, 0, scaled);
}

void FrameView::newFrame(const QPixmap &frame) {
    _pixMap = frame;
    update();
}
