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

#include "datacontainer.h"
#include "wavewidget.h"
#include "vectorwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dataContainer = new DataContainer(ui);
    waveWidget = new WaveWidget(dataContainer, ui->centralWidget);
    vectorWidget = new VectorWidget(dataContainer, ui->centralWidget);

    connect(&timer, SIGNAL(timeout()), this, SLOT(stepWidgets()));
    connect(ui->actionWave_Supperposition, SIGNAL(triggered()), this, SLOT(show_waveWidget()));
    connect(ui->actionVectors, SIGNAL(triggered()), this, SLOT(show_vectorWidget()));

    ui->gridLayout_2->addWidget(waveWidget, 0, 1, -1, -1);
    ui->gridLayout_2->addWidget(vectorWidget, 0, 1, -1, -1);

    show_waveWidget();

}

MainWindow::~MainWindow()
{
    delete waveWidget;
    delete dataContainer;
    delete ui;
}

void MainWindow::stepWidgets()
{
    dataContainer->update();

    if (int(ui->time->value() * 1000) != timer.interval() && timer.isActive()) {
        timer.start(ui->time->value() * 1000);
    }

    ui->lcdNumber->display(dataContainer->data[DataContainer::ElapsedTime]);

    waveWidget->step();
    vectorWidget->step();
}

void MainWindow::show_waveWidget()
{
    vectorWidget->hide();

    connect(ui->wave1_toggle, SIGNAL(stateChanged(int)), waveWidget, SLOT(show_wave1(int)));
    connect(ui->wave2_toggle, SIGNAL(stateChanged(int)), waveWidget, SLOT(show_wave2(int)));

    waveWidget->show();
}

void MainWindow::show_vectorWidget()
{
    waveWidget->hide();

    connect(ui->wave1_toggle, SIGNAL(stateChanged(int)), vectorWidget, SLOT(show_wave1(int)));
    connect(ui->wave2_toggle, SIGNAL(stateChanged(int)), vectorWidget, SLOT(show_wave2(int)));

    vectorWidget->show();

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

    waveWidget->reset();
    vectorWidget->reset();
}
