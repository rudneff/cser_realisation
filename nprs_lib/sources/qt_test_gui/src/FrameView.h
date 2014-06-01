#ifndef FRAMEVIEW_H
#define FRAMEVIEW_H

#include <qwidget.h>

class FrameView : public QWidget 
{
    Q_OBJECT
public:
    explicit FrameView(QWidget *parent = 0);

public slots:
    void newFrame(const QPixmap &pm);

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    QPixmap _pixMap;
};

#endif // FRAMEVIEW_H