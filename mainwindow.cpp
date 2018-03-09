#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->redMinSlider->setValue(ui->imageView->redMin());
    ui->redMaxSlider->setValue(ui->imageView->redMax());
    ui->greenMinSlider->setValue(ui->imageView->greenMin());
    ui->greenMaxSlider->setValue(ui->imageView->greenMax());
    ui->blueMinSlider->setValue(ui->imageView->blueMin());
    ui->blueMaxSlider->setValue(ui->imageView->blueMax());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_redMinSlider_valueChanged(int value)
{
    ui->imageView->setRedMin(value);
    ui->imageView->saveValues();
}

void MainWindow::on_redMaxSlider_valueChanged(int value)
{
    ui->imageView->setRedMax(value);
    ui->imageView->saveValues();
}

void MainWindow::on_greenMinSlider_valueChanged(int value)
{
    ui->imageView->setGreenMin(value);
    ui->imageView->saveValues();
}

void MainWindow::on_greenMaxSlider_valueChanged(int value)
{
    ui->imageView->setGreenMax(value);
    ui->imageView->saveValues();
}

void MainWindow::on_blueMinSlider_valueChanged(int value)
{
    ui->imageView->setBlueMin(value);
    ui->imageView->saveValues();
}

void MainWindow::on_blueMaxSlider_valueChanged(int value)
{
    ui->imageView->setBlueMax(value);
    ui->imageView->saveValues();
}
