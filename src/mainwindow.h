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
#include <QMap>
#include <QString>

namespace Ui
{
    class MainWindow;
}

class LabWidget;
class DataContainer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    DataContainer * dataContainer;
    QTimer supPos_timer;
    QTimer intensity_timer;
    QMap<QString, LabWidget *> widgets;

    void removeWidgets(QLayout *);
    void resetWidgets();
    void setupTab_0();
    void setupTab_1();

private slots:
    void show_about();
    void changedTab(int tabIndex);

    void supPos_run();
    void supPos_step();
    void supPos_stepWidgets();
    void supPos_reset();
    void supPos_showA(int);
    void supPos_showB(int);

    void intensity_run();
    void intensity_step();
    void intensity_stepWidgets();
    void intensity_reset();
};

#endif // MAINWINDOW_H
