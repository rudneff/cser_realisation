#ifndef FRAMEVIEW_H
#define FRAMEVIEW_H

#include <qwidget.h>

class FrameView : public QWidget 
{
    Q_OBJECT
public:
    explicit FrameView(QWidget *parent = 0);

    QImage & frame() { return _frame; }

public slots:
    void newFrame(const QImage &frame);

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    QImage _frame;
};

#endif // FRAMEVIEW_H
