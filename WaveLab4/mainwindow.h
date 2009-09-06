/*
Copyright 2009 James Benton Anglin
This program is distributed under the terms of the GNU General Public License

This file is part of WaveLab.

WaveLab is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

WaveLab is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with WaveLab.  If not, see <http://www.gnu.org/licenses/>.
 */

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
    void icon();

private slots:
    void show_waveWidget();
    void show_vectorWidget();
    void show_about();

    void stepWidgets();

    void on_runButton_clicked();
    void on_stepButton_clicked();
    void on_resetButton_clicked();

};

#endif // MAINWINDOW_H
