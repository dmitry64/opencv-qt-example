#include "imageview.h"

#include <QPainter>
#include <QSettings>


ImageView::ImageView(QWidget *parent) : QWidget(parent)
{
    _cap = new cv::VideoCapture(" v4l2src ! video/x-raw,framerate=30/1 ! videoconvert ! appsink ");

    assert(_cap->isOpened());

    QSettings settings("Home-Dev","opencv-example");

    _redMin = settings.value("RedMin",20).toInt();
    _redMax = settings.value("RedMax",200).toInt();
    _greenMin = settings.value("GreenMin",20).toInt();
    _greenMax = settings.value("GreenMax",200).toInt();
    _blueMin = settings.value("BlueMin",20).toInt();
    _blueMax = settings.value("BlueMax",200).toInt();

}

void ImageView::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    cv::Mat img;
    _cap->operator >>(img);

    cvtColor(img, img, cv::COLOR_BGR2RGB);
    QImage qimageOriginal((uchar*) img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    painter.drawImage(QRect(0,0,width()/2,height()/3),qimageOriginal);

    cv::Mat out1;
    cv::GaussianBlur(img, out1, cv::Size(9, 9), 2, 2);
    QImage qimageRes1((uchar*) out1.data, out1.cols, out1.rows, out1.step, QImage::Format_RGB888);
    painter.drawImage(QRect(width()/2,0,width()/2,height()/3),qimageRes1);

    cv::Mat out2;
    cv::inRange(out1, cv::Scalar(_redMin, _greenMin, _blueMin), cv::Scalar(_redMax, _greenMax, _blueMax), out2);
    QImage qimageRes2((uchar*) out2.data, out2.cols, out2.rows, out2.step, QImage::Format_Grayscale8);
    painter.drawImage(QRect(width()/2,height()/3,width()/2,height()/3),qimageRes2);

    cv::Mat out3;
    cv::erode(out2, out3, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(10, 10)) );
    QImage qimageRes3((uchar*) out3.data, out3.cols, out3.rows, out3.step, QImage::Format_Grayscale8);
    painter.drawImage(QRect(0,height()/3,width()/2,height()/3),qimageRes3);

    cv::Mat out4;
    cv::dilate( out3, out4, cv::getStructuringElement(cv::MORPH_RECT, cv::Size(50, 50)) );
    QImage qimageRes4((uchar*) out4.data, out4.cols, out4.rows, out4.step, QImage::Format_Grayscale8);
    painter.drawImage(QRect(0,height()*2/3,width()/2,height()/3),qimageRes4);

    cv::Mat out5;
    img.copyTo(out5,out4);
    QImage qimageRes5((uchar*) out5.data, out5.cols, out5.rows, out5.step, QImage::Format_RGB888);
    painter.drawImage(QRect(width()/2,height()*2/3,width()/2,height()/3),qimageRes5);

    update();
}

int ImageView::blueMax() const
{
    return _blueMax;
}

void ImageView::setBlueMax(int blueMax)
{
    _blueMax = blueMax;
}

int ImageView::greenMax() const
{
    return _greenMax;
}

void ImageView::setGreenMax(int greenMax)
{
    _greenMax = greenMax;
}

int ImageView::redMax() const
{
    return _redMax;
}

void ImageView::setRedMax(int redMax)
{
    _redMax = redMax;
}

int ImageView::blueMin() const
{
    return _blueMin;
}

void ImageView::setBlueMin(int blueMin)
{
    _blueMin = blueMin;
}

int ImageView::greenMin() const
{
    return _greenMin;
}

void ImageView::setGreenMin(int greenMin)
{
    _greenMin = greenMin;
}

int ImageView::redMin() const
{
    return _redMin;
}

void ImageView::setRedMin(int redMin)
{
    _redMin = redMin;
}

void ImageView::saveValues()
{
    QSettings settings("Home-Dev","opencv-example");

    settings.setValue("RedMin",_redMin);
    settings.setValue("RedMax",_redMax);

    settings.setValue("GreenMin",_greenMin);
    settings.setValue("GreenMax",_greenMax);

    settings.setValue("BlueMin",_blueMin);
    settings.setValue("BlueMax",_blueMax);
}
