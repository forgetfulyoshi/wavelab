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

#include <iostream>

#include "datacontainer.h"
#include "labwidget.h"
#include "wavewidget.h"
#include "vectorwidget.h"
#include <QMap>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        widgets(QMap<QString, LabWidget *>()),
        dataContainer(new DataContainer(ui))
{
    ui->setupUi(this);

    widgets["WaveWidget"] = new WaveWidget(dataContainer, ui->centralWidget);
    widgets["VectorWidget"] = new VectorWidget(dataContainer, ui->centralWidget);

    connect(&timer, SIGNAL(timeout()), this, SLOT(stepWidgets()));
    //connect(ui->actionWave_Supperposition, SIGNAL(triggered()), this, SLOT(showWidget()));
    //connect(ui->actionVectors, SIGNAL(triggered()), widgets["VectorWidget"], SLOT(show()));
    connect(ui->actionAbout_WaveLab, SIGNAL(triggered()), this, SLOT(show_about()));
    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    QMap<QString, LabWidget *>::const_iterator i = widgets.constBegin();
    while (i != widgets.constEnd()) {
        ui->gridLayout_2->addWidget(i.value(), 0, 1, -1, -1);
        ++i;
    }

    showWidget(widgets["WaveWidget"]);
}

MainWindow::~MainWindow()
{
    delete dataContainer;
    delete ui;
}

void MainWindow::on_actionWave_Supperposition_triggered()
{
    showWidget(widgets["WaveWidget"]);
}

void MainWindow::on_actionVectors_triggered()
{
    showWidget(widgets["VectorWidget"]);
}

void MainWindow::stepWidgets()
{
    dataContainer->update();

    if (int(ui->time->value() * 1000) != timer.interval() && timer.isActive()) {
        timer.start(ui->time->value() * 1000);
    }

    ui->lcdNumber->display(dataContainer->data[DataContainer::ElapsedTime]);

    // Step all the widgets
    QMap<QString, LabWidget *>::const_iterator i = widgets.constBegin();
    while (i != widgets.constEnd()) {
        i.value()->step();
        ++i;
    }
}

void MainWindow::showWidget(LabWidget * widget)
{
    // First, go through and hide all the widgets
    QMap<QString, LabWidget *>::const_iterator i = widgets.constBegin();
    while (i != widgets.constEnd()) {
        i.value()->hide();
        ++i;
    }

    // Then, connect the appropriate signals and slots (inherited to all widgets by LabWidget)
    connect(ui->wave1_toggle, SIGNAL(stateChanged(int)), widget, SLOT(show_wave1(int)));
    connect(ui->wave2_toggle, SIGNAL(stateChanged(int)), widget, SLOT(show_wave2(int)));

    // Finally, show the desired widget
    widget->show();
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
