#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_genButton_clicked();

    void on_minimumInput_editingFinished();

    void on_maximumInput_editingFinished();

private:
    Ui::MainWindow *ui;
    int minimumValue;
    int maximumValue;
};

#endif // MAINWINDOW_H
