#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_redMinSlider_valueChanged(int value);
    void on_redMaxSlider_valueChanged(int value);
    void on_greenMinSlider_valueChanged(int value);
    void on_greenMaxSlider_valueChanged(int value);
    void on_blueMinSlider_valueChanged(int value);
    void on_blueMaxSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
