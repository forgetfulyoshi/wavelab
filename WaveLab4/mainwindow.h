#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTimer>

namespace Ui
{
    class MainWindow;
}

class WaveWidget;
class VectorWidget;
class DataContainer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    WaveWidget * waveWidget;
    VectorWidget * vectorWidget;
    DataContainer * dataContainer;
    QTimer timer;

private slots:
    void show_waveWidget();
    void show_vectorWidget();

    void stepWidgets();

    void on_runButton_clicked();
    void on_stepButton_clicked();
    void on_resetButton_clicked();

};

#endif // MAINWINDOW_H
