#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv.hpp>
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <QVector>
#include <QImage>
#include <QRgb>
#include <QPixmap>
#include <cv.h>
#include <highgui.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_open_pushButton_clicked();

    void on_brightness_horizontalSlider_valueChanged(int value);

    void on_grayscale_pushButton_clicked();

    void on_red_horizontalSlider_valueChanged(int value);

    void on_green_horizontalSlider_valueChanged(int value);

    void on_blue_horizontalSlider_valueChanged(int value);

    void on_blur_pushButton_clicked();

    void on_save_pushButton_clicked();

    void on_negative_pushButton_clicked();

    void on_contrast_horizontalSlider_valueChanged(int value);

    void on_clear_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    cv::Mat realimg;

    cv::Mat img;

    cv::Mat temp;

    void changeColor(const cv::Mat &src, cv::Mat &dst, QVector<int> value);

    QImage Mat2QImage(const cv::Mat src);

    void showImage(const cv::Mat &src);

};

#endif // MAINWINDOW_H
