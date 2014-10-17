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
    void recognize();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    nprs::RecognitionSystem _recSystem;

    void performRecognition(QImage &frame);
    void testSobel(QImage &frame);
    void testResize(QImage &frame);
};

#endif // MAINWINDOW_H
