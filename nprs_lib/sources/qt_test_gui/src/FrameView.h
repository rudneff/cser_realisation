#ifndef FRAMEVIEW_H
#define FRAMEVIEW_H

#include <qwidget.h>

class FrameView : public QWidget 
{
    Q_OBJECT
public:
    

protected:
    void paintEvent(QPaintEvent*) override;

private:
    

};

#endif // FRAMEVIEW_H