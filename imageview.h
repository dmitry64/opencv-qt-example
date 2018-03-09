#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QWidget>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

class ImageView : public QWidget
{
    Q_OBJECT
public:
    explicit ImageView(QWidget *parent = nullptr);

    int redMin() const;
    void setRedMin(int redMin);

    int greenMin() const;
    void setGreenMin(int greenMin);

    int blueMin() const;
    void setBlueMin(int blueMin);

    int redMax() const;
    void setRedMax(int redMax);

    int greenMax() const;
    void setGreenMax(int greenMax);

    int blueMax() const;
    void setBlueMax(int blueMax);

    void saveValues();

protected:
    void paintEvent(QPaintEvent *event) override;
private:
    cv::VideoCapture * _cap;
    int _redMin;
    int _greenMin;
    int _blueMin;
    int _redMax;
    int _greenMax;
    int _blueMax;

signals:

public slots:
};

#endif // IMAGEVIEW_H
