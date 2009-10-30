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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui>
#include <QMap>
#include <QString>

#include "datacontainer.h"
#include "labwidget.h"
#include "wavewidget.h"
#include "vectorwidget.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        dataContainer(new DataContainer(ui)),
        widgets(QMap<QString, LabWidget *>())
{
    ui->setupUi(this);

    widgets["WaveWidget"] = new WaveWidget(dataContainer, ui->centralWidget);
    widgets["VectorWidget"] = new VectorWidget(dataContainer, ui->centralWidget);

    connect(&timer, SIGNAL(timeout()), this, SLOT(stepWidgets()));

    connect(ui->actionAbout_WaveLab, SIGNAL(triggered()), this, SLOT(show_about()));
    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    ui->gridLayout_5->addWidget(widgets["VectorWidget"], 1, 0, 1,1);
    ui->gridLayout_5->addWidget(widgets["WaveWidget"], 1, 1, 1, 1);

    QMap<QString, LabWidget *>::const_iterator i = widgets.constBegin();
    while (i != widgets.constEnd()) {
        connect(ui->wave1_toggle, SIGNAL(stateChanged(int)), i.value(), SLOT(show_wave1(int)));
        connect(ui->wave2_toggle, SIGNAL(stateChanged(int)), i.value(), SLOT(show_wave2(int)));
        ++i;
    }
}

MainWindow::~MainWindow()
{
    delete dataContainer;
    delete ui;
}


void MainWindow::stepWidgets()
{
    dataContainer->update();

    if (int(ui->time->value() * 1000) != timer.interval() && timer.isActive()) {
        timer.start(ui->time->value() * 1000);
    }

    double range = dataContainer->data[DataContainer::Wave1_Amp] + dataContainer->data[DataContainer::Wave2_Amp];

    ui->lcdNumber->display(dataContainer->data[DataContainer::ElapsedTime]);

    // Step all the widgets
    QMap<QString, LabWidget *>::const_iterator i = widgets.constBegin();
    while (i != widgets.constEnd()) {
        i.value()->setYScale(range);
        i.value()->setXScale(range);
        i.value()->step();
        ++i;
    }
}

void MainWindow::show_about()
{
    QMessageBox::about(this, tr("About WaveLab"),
                       tr("WaveLab\n\n"

                          "Copyright 2009 James Benton Anglin\n\n "
                          "This program is distributed under the terms of the GNU General Public License "

                          "WaveLab is free software: you can redistribute it and/or modify "
                          "it under the terms of the GNU General Public License as published by "
                          "the Free Software Foundation, either version 3 of the License, or "
                          "(at your option) any later version. "

                          "WaveLab is distributed in the hope that it will be useful, "
                          "but WITHOUT ANY WARRANTY; without even the implied warranty of "
                          "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the "
                          "GNU General Public License for more details. "

                          "You should have received a copy of the GNU General Public License "
                          "along with WaveLab.  If not, see <http://www.gnu.org/licenses/>."));
}

void MainWindow::on_runButton_clicked()
{
    if (!timer.isActive()) {
        timer.start(ui->time->value() * 1000);
        ui->runButton->setText("Pause");
    } else {
        timer.stop();
        ui->runButton->setText("Run");
    }
}

void MainWindow::on_stepButton_clicked()
{
    if (timer.isActive()) {
        timer.stop();
        ui->runButton->setText("Run");
    }
    stepWidgets();

}

void MainWindow::on_resetButton_clicked()
{
    timer.stop();

    dataContainer->resetTime();
    ui->runButton->setText("Run");
    ui->lcdNumber->display(0.0);

    // Reset all the widgets
    QMap<QString, LabWidget *>::const_iterator i = widgets.constBegin();
    while (i != widgets.constEnd()) {
        i.value()->reset();
        ++i;
    }
}
