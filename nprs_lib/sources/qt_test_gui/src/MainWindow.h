#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <rec_system/RecognitionSystem.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void newFrame(const QImage &image);
    void loadFile();
    void exit();

private:
    Ui::MainWindow *ui;
    nprs::RecognitionSystem _recSystem;
};

#endif // MAINWINDOW_H