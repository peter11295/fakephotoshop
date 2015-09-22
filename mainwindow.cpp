#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName();
    cv::Mat src;
    src = cv::imread(fileName.toStdString());

    int width = src.cols;
    int height = src.rows;
    cv::resize(src,src,cv::Size(width/2,height/2));
    this->img = src.clone();
    this->temp= src.clone();
    this->realimg= src.clone();
    this->showImage(this->img);

}

QImage MainWindow::Mat2QImage(const cv::Mat src)
{

    if(src.type()==CV_8UC1)
    {
        QVector<QRgb> colorTable;
        for (int i=0; i<256; i++)
            colorTable.push_back(qRgb(i,i,i));
        const uchar *qImageBuffer = (const uchar*)src.data;
        QImage img(qImageBuffer, src.cols, src.rows, src.step, QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }

    if(src.type()==CV_8UC3)
    {
        const uchar *qImageBuffer = (const uchar*)src.data;
        QImage img(qImageBuffer, src.cols, src.rows, src.step, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "Error! Can't convert image type.";
        return QImage();
    }
}

void MainWindow::showImage(const cv::Mat &src)
{
    cv::Mat dst;
    int width = ui->label->width();
    int height = ui->label->height();
    double ratio = (double)width / (double)height;
    double imgRatio = src.cols / src.rows;

    if (ratio<imgRatio)
       {
           cv::resize(src,dst,cv::Size(width,(src.rows*width)/src.cols));
       }
       else
       {
           cv::resize(src,dst,cv::Size((src.cols*height)/src.rows,height));
       }

    ui->label->setPixmap(QPixmap::fromImage(this->Mat2QImage(dst)));
}

void MainWindow::on_brightness_horizontalSlider_valueChanged(int value)
{
    cv::Mat dst=temp;

    for(int i = 0 ;i < this->img.rows ; i++)
    {
        for(int j = 0 ;j< this->img.cols ; j++)
        {
            for(int k = 0 ;k < this->img.channels() ; k++)
            {
                if(this->img.at<cv::Vec3b>(i,j)[k]+value > 255)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 255;
                }
                else if(this->img.at<cv::Vec3b>(i,j)[k]+value < 0)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 0;
                }
                else
                {
                    dst.at<cv::Vec3b>(i,j)[k] =
                              this->img.at<cv::Vec3b>(i,j)[k]+value;
                }
            }
        }
    }
//    this->temp=dst.clone();

    this->showImage(dst);
}

void MainWindow::on_grayscale_pushButton_clicked()
{
    cv::Mat src = this->img;
    cv::Mat dst;

    dst.create(cv::Size(src.cols,src.rows),CV_8UC1);
    for(int i = 0 ;i < src.rows ; i++)
    {
        for(int j = 0 ;j< src.cols ; j++)
        {

            dst.at<uchar>(i,j)
                    = (src.at<cv::Vec3b>(i,j)[0]
                    +src.at<cv::Vec3b>(i,j)[1]
                    +src.at<cv::Vec3b>(i,j)[2])/3;
        }
    }
    ui->blur_pushButton->setDisabled(1);
    ui->contrast_horizontalSlider->setDisabled(1);
    ui->blue_horizontalSlider->setDisabled(1);
    ui->green_horizontalSlider->setDisabled(1);
    ui->red_horizontalSlider->setDisabled(1);
    ui->negative_pushButton->setDisabled(1);
    ui->brightness_horizontalSlider->setDisabled(1);

    this->showImage(dst);


}

void MainWindow::changeColor(const cv::Mat &src, cv::Mat &dst, QVector<int> value)
{
    for(int i = 0 ;i < src.rows ; i++)
    {
        for(int j = 0 ;j< src.cols ; j++)
        {
            for(int k = 0 ;k < src.channels() ; k++)
            {
                if(src.at<cv::Vec3b>(i,j)[k]+value[k] > 255)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 255;
                }
                else if(src.at<cv::Vec3b>(i,j)[k]+value[k] < 0)
                {
                    dst.at<cv::Vec3b>(i,j)[k] = 0;
                }
                else
                {
                    dst.at<cv::Vec3b>(i,j)[k] =
                            src.at<cv::Vec3b>(i,j)[k]+value[k];
                }
            }
        }
    }
}

void MainWindow::on_red_horizontalSlider_valueChanged(int value)
{
    cv::Mat src=temp;
    QVector<int> valueVec(3);
    valueVec[0] = ui->blue_horizontalSlider->value();
    valueVec[1] = ui->green_horizontalSlider->value();
    valueVec[2] = ui->red_horizontalSlider->value();

    this->changeColor(this->img,src,valueVec);
    this->showImage(src);


}

void MainWindow::on_green_horizontalSlider_valueChanged(int value)
{
    cv::Mat src=temp;
    QVector<int> valueVec(3);
    valueVec[0] = ui->blue_horizontalSlider->value();
    valueVec[1] = ui->green_horizontalSlider->value();
    valueVec[2] = ui->red_horizontalSlider->value();

    this->changeColor(this->img,src,valueVec);
    this->showImage(src);


}


void MainWindow::on_blue_horizontalSlider_valueChanged(int value)
{
    cv::Mat src=temp;
    QVector<int> valueVec(3);
    valueVec[0] = ui->blue_horizontalSlider->value();
    valueVec[1] = ui->green_horizontalSlider->value();
    valueVec[2] = ui->red_horizontalSlider->value();
    this->changeColor(this->img,src,valueVec);
    this->showImage(src);


}

void MainWindow::on_blur_pushButton_clicked()
{
    cv::Mat src = this->temp;
    cv::Mat dst(src);

    for(int i = 1 ;i < src.rows-1 ; i++)
    {
        for(int j = 1 ;j< src.cols-1 ; j++)
        {

            for(int k = 0;k < src.channels();k++)
            {
                dst.at<cv::Vec3b>(i,j)[k] =
                        (src.at<cv::Vec3b>(i-1,j-1)[k]
                        +src.at<cv::Vec3b>(i-1,j)[k]
                        +src.at<cv::Vec3b>(i-1,j+1)[k]
                        +src.at<cv::Vec3b>(i,j-1)[k]
                        +src.at<cv::Vec3b>(i,j)[k]
                        +src.at<cv::Vec3b>(i,j+1)[k]
                        +src.at<cv::Vec3b>(i+1,j-1)[k]
                        +src.at<cv::Vec3b>(i+1,j)[k]
                        +src.at<cv::Vec3b>(i+1,j+1)[k])/9;
            }
        }
    }
    this->showImage(dst);
}

void MainWindow::on_save_pushButton_clicked()
{
    cv::Mat src=this->temp;
    cv::imshow("",src);
    cv::imwrite("processed.bmp",src);
}

void MainWindow::on_negative_pushButton_clicked()
{

    cv::Mat dst(temp);

    for(int i = 1 ;i < dst.rows-1 ; i++)
    {
        for(int j = 1 ;j< dst.cols-1 ; j++)
        {

            for(int k = 0;k < dst.channels();k++)
            {
                dst.at<cv::Vec3b>(i,j)[k] =255-dst.at<cv::Vec3b>(i,j)[k];
            }
        }
    }
    this->showImage(dst);

}


void MainWindow::on_contrast_horizontalSlider_valueChanged(int value)
{
    cv::Mat src = img;
    cv::Mat dst=src.clone();
    cv::Mat dst2=temp;

    double Delta;
    double a,b;
    int x,y;
    int contrast=(ui->contrast_horizontalSlider->value());
    int brightness=(ui->brightness_horizontalSlider->value())*100/255;

    for(int i = 1 ;i < src.rows-1 ; i++)
    {
        for(int j = 1 ;j< src.cols-1 ; j++)
        {

            for(int k = 0;k < src.channels();k++)
            {
                x=dst.at<cv::Vec3b>(i,j)[k];

                if (contrast>0)
                {
                    Delta=127*contrast/100;
                    a=255/(255-Delta*2);
                    b=a*(brightness-Delta);

                    y=int (a*x+b);

                    if (y<0)
                        y=0;
                    if (y>255)
                        y=255;
                }
                else
                {
                    Delta=-128*contrast/100;
                    a=(256-Delta*2)/255;
                    b=a*brightness+Delta;

                    for(int x=0;x<256;x++)
                    {
                        y=int (a*x+b);

                        if (y<0)
                            y=0;
                        if (y>255)
                            y=255;
                    }
                }
                dst2.at<cv::Vec3b>(i,j)[k]=y;

            }
        }
    }
    this->showImage(dst2);


}

void MainWindow::on_clear_pushButton_clicked()
{
    this->temp=realimg.clone();
    this->img=realimg.clone();

    ui->blur_pushButton->setDisabled(0);
    ui->contrast_horizontalSlider->setDisabled(0);
    ui->contrast_horizontalSlider->setValue(1);
    ui->blue_horizontalSlider->setDisabled(0);
    ui->blue_horizontalSlider->setValue(0);
    ui->green_horizontalSlider->setDisabled(0);
    ui->green_horizontalSlider->setValue(0);
    ui->red_horizontalSlider->setDisabled(0);
    ui->red_horizontalSlider->setValue(0);
    ui->negative_pushButton->setDisabled(0);
    ui->brightness_horizontalSlider->setDisabled(0);
    ui->brightness_horizontalSlider->setValue(0);

    this->showImage(this->temp);
}
