#include "ui/mainwindow.h"
#include "rnglogic.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , minimumValue(1)
    , maximumValue(100)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_minimumInput_editingFinished()
{
    minimumValue = ui->minimumInput->text().toInt();  // Try conversion
    if (ui->minimumInput->text().isEmpty() || minimumValue == 0) {
        ui->minimumInput->setText("0");
        minimumValue = 0;
    }

    if (minimumValue > maximumValue) {
        minimumValue = maximumValue;
        ui->minimumInput->setText(QString::number(minimumValue));
        qDebug() << "Minimum cannot be greater than maximum. Resetting minimum.";
        ui->result->setText(QString("Min. cannot be greater than max."));
    }
}

void MainWindow::on_maximumInput_editingFinished()
{
    maximumValue = ui->maximumInput->text().toInt();  // Try conversion
    if (ui->maximumInput->text().isEmpty() || maximumValue == 0) {
        ui->maximumInput->setText("5");
        maximumValue = 5;
    }

    if (minimumValue > maximumValue) {
        minimumValue = maximumValue;
        ui->minimumInput->setText(QString::number(minimumValue));
        qDebug() << "Minimum cannot be greater than maximum. Resetting minimum.";
        ui->result->setText(QString("Min. cannot be greater than max."));
    }
}

void MainWindow::on_genButton_clicked()
{
    RNGLogic rng;
    int number = rng.generate(minimumValue, maximumValue); // example range
    qDebug() << "Random number:" << number;

    ui->result->setText(QString::number(number));
}


