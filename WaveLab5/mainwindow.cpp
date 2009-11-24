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
#include "intensitywavewidget.h"
#include "intensityvectorwidget.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        dataContainer(new DataContainer(ui)),
        widgets(QMap<QString, LabWidget *>())
{
    ui->setupUi(this);

    connect(&supPos_timer, SIGNAL(timeout()), this, SLOT(supPos_stepWidgets()));
    connect(&intensity_timer, SIGNAL(timeout()), this, SLOT(intensity_stepWidgets()));

    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(changedTab(int)));

    connect(ui->actionAbout_WaveLab, SIGNAL(triggered()), this, SLOT(show_about()));
    connect(ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    setupTab_0();

    // Connect superpositon buttons
    connect(ui->runButton, SIGNAL(clicked()), this, SLOT(supPos_run()));
    connect(ui->stepButton, SIGNAL(clicked()), this, SLOT(supPos_step()));
    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(supPos_reset()));

    // Connect intensity buttons
    connect(ui->int_runButton, SIGNAL(clicked()), this, SLOT(intensity_run()));
    connect(ui->int_stepButton, SIGNAL(clicked()), this, SLOT(intensity_step()));
    connect(ui->int_resetButton, SIGNAL(clicked()), this, SLOT(intensity_reset()));
}

MainWindow::~MainWindow()
{
    delete dataContainer;
    delete ui;
}

void MainWindow::changedTab(int tabIndex)
{
    switch(tabIndex)
    {

    case 0: // Superposition Tab
        // Reset widgets from Intensity tab (IF they exist)
        intensity_reset();

        // Set up Superposition Tab
        if (!(widgets.contains("WaveWidget") && widgets.contains("VectorWidget"))) {
            setupTab_0();
        }

        break;

    case 1: // Intensity Tab
        // Reset widgets from Superposition tab layout (IF they exist)
        supPos_reset();

        // Set up Intensity tab
        if (!(widgets.contains("IntensityWave") && widgets.contains("IntensityVector"))) {
            setupTab_1();
        }

        break;
    }
}

//----------------------------------------------------
// Handle Superposition Tab Buttons

// Run / Pause
void MainWindow::supPos_run()
{
    
    
    if (!supPos_timer.isActive()) {
        supPos_timer.start(ui->time->value() * 1000);
        ui->runButton->setText("Pause");
    } else {
        supPos_timer.stop();
        ui->runButton->setText("Run");
    }
}

// Step
void MainWindow::supPos_step()
{
    if (supPos_timer.isActive()) {
        supPos_timer.stop();
        ui->runButton->setText("Run");
    }
    supPos_stepWidgets();
}

void MainWindow::supPos_stepWidgets()
{
    dataContainer->update();

    if (int(ui->time->value() * 1000) != supPos_timer.interval() && supPos_timer.isActive()) {
        supPos_timer.start(ui->time->value() * 1000);
    }

    ui->lcdNumber->display(dataContainer->data[DataContainer::ElapsedTime]);
    double range = dataContainer->data[DataContainer::Wave1_Amp] + dataContainer->data[DataContainer::Wave2_Amp];

    widgets["WaveWidget"]->setXScale(range);
    widgets["WaveWidget"]->setYScale(range);

    widgets["VectorWidget"]->setXScale(range);
    widgets["VectorWidget"]->setYScale(range);

    widgets["WaveWidget"]->step();
    widgets["VectorWidget"]->step();
}

// Reset
void MainWindow::supPos_reset()
{
    supPos_timer.stop();

    dataContainer->resetTime();
    ui->runButton->setText("Run");
    ui->lcdNumber->display(0.0);

    resetWidgets();

}
//-------------------------------------------------

//-------------------------------------------------
// Handle Intensity Tab buttons

// Run/Pause
void MainWindow::intensity_run()
{
    if (!intensity_timer.isActive()) {
        intensity_timer.start(ui->int_speed->value());
        ui->int_runButton->setText("Pause");
    } else {
        intensity_timer.stop();
        ui->int_runButton->setText("Run");
    }
}

// Step
void MainWindow::intensity_step()
{
    if (intensity_timer.isActive()) {
        intensity_timer.stop();
        ui->int_runButton->setText("Run");
    }
    intensity_stepWidgets();
}

void MainWindow::intensity_stepWidgets()
{
    dataContainer->update();

    if (ui->int_speed->value() != intensity_timer.interval() && intensity_timer.isActive()) {
        intensity_timer.start(ui->int_speed->value());
    }

    widgets["IntensityVector"]->setXScale(dataContainer->data[DataContainer::NumSlits]);
    widgets["IntensityVector"]->setYScale(dataContainer->data[DataContainer::NumSlits]);

    widgets["IntensityWave"]->setXScale(0);
    widgets["IntensityWave"]->setYScale(0);

    widgets["IntensityVector"]->step();
    widgets["IntensityWave"]->step();
}

// Reset
void MainWindow::intensity_reset()
{
    intensity_timer.stop();

    dataContainer->resetTime();
    ui->int_runButton->setText("Run");

    resetWidgets();
}
//-------------------------------------------------

// Remove all widgets from a given layout and memory
void MainWindow::removeWidgets(QLayout * layout)
{
    // Remove widgets from layout
    QLayoutItem * child;
    while ((child = layout->takeAt(0)) != 0) {
        layout->removeItem(child);
    }

    // Delete all widgets from memory
    QMap<QString, LabWidget *>::const_iterator i = widgets.constBegin();
    while (i != widgets.constEnd()) {
        delete i.value();
        ++i;
    }
    // Clear the map
    widgets.clear();
}

// Reset all the widgets in widgets map
void MainWindow::resetWidgets()
{
    QMap<QString, LabWidget *>::const_iterator i = widgets.constBegin();
    while (i != widgets.constEnd()) {
        i.value()->reset();
        ++i;
    }
}

void MainWindow::setupTab_0() // Superposition Tab
{
    // Create LabWidgets in Superposition tab and add to widgets map
    widgets["WaveWidget"] = new WaveWidget(dataContainer, NULL);
    widgets["VectorWidget"] = new VectorWidget(dataContainer, NULL);

    // Place widgets in tab_0_layout
    ui->tab_0_layout->addWidget(widgets["WaveWidget"], 0,1,1,1);
    ui->tab_0_layout->addWidget(widgets["VectorWidget"], 0,0,1,1);
}

void MainWindow::setupTab_1() // Intensity Tab
{
    // Create LabWidgets in Intensity tab and add to widgets map
    widgets["IntensityWave"] = new IntensityWaveWidget(dataContainer, NULL);
    widgets["IntensityVector"] = new IntensityVectorWidget(dataContainer, NULL);

    // Place widgets in tab_1_layout
    ui->tab_1_layout->addWidget(widgets["IntensityWave"], 0,1,1,1);
    ui->tab_1_layout->addWidget(widgets["IntensityVector"], 0,0,1,1);
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
