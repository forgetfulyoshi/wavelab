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

#include "wavewidget.h"
#include "datacontainer.h"

#include <cmath>
#include <qcolor.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_scaleitem.h>

WaveWidget::WaveWidget(DataContainer * d, QWidget * parent) :
        LabWidget(d, parent),
        wave1(new QwtPlotCurve("Wave 1")),
        wave2(new QwtPlotCurve("Wave 2")),
        supWave(new QwtPlotCurve("Superposition Wave")),
        wave1_pen(new QPen(Qt::green)),
        wave2_pen(new QPen(Qt::red)),
        supWave_pen(new QPen(Qt::black)),
        xScale(new QwtPlotScaleItem(QwtScaleDraw::BottomScale, frameWidth() / 2.0)),
        yScale(new QwtPlotScaleItem(QwtScaleDraw::RightScale))
{
    xScale->attach(this);
    enableAxis(QwtPlot::xBottom, false);

    yScale->attach(this);
    enableAxis(QwtPlot::yLeft, false);

    //-------------------------------
    // Modify line widths, 1 is normal

    wave1_pen->setWidthF(1.5);
    wave2_pen->setWidthF(1.5);
    supWave_pen->setWidthF(1.5);
    //-------------------------------

    wave1->setPen(*wave1_pen);
    wave2->setPen(*wave2_pen);
    supWave->setPen(*supWave_pen);
}

WaveWidget::~WaveWidget()
{
    delete wave1;
    delete wave2;
    delete supWave;
    delete wave1_pen;
    delete wave2_pen;
    delete supWave_pen;
    delete xScale;
    delete yScale;
}

void WaveWidget::setXScale(double)
{
    setAxisScale(2, dataContainer->data[DataContainer::ElapsedTime], dataContainer->data[DataContainer::ElapsedTime] - 10);
}

void WaveWidget::step()
{
    getCurrentValues();

    x.append(elapsedTime);
    wave1_y.append(wave1_amplitude * sin(wave1_frequency * elapsedTime));
    wave2_y.append(wave2_amplitude * sin(wave2_frequency * elapsedTime + phaseShift));
    supWave_y.append(wave1_y.back() + wave2_y.back());

    // Set the data and attach Wave 1 to the graph
    wave1->setData(x, wave1_y);
    wave1->attach(this);

    // Set the data and attach Wave 2 to the graph
    wave2->setData(x, wave2_y);
    wave2->attach(this);

    // Set the data and attach the Superposition wave to the graph
    supWave->setData(x, supWave_y);
    supWave->attach(this);

    yScale->setPosition(dataContainer->data[DataContainer::ElapsedTime]); // Keep the y axis on the left side

    // Update the graph with new data
    replot();

}

void WaveWidget::reset()
{
    wave1_y.clear();
    wave2_y.clear();
    supWave_y.clear();
    x.clear();

    wave1->detach();
    wave2->detach();
    supWave->detach();

    this->replot();
}

void WaveWidget::show_wave1(int state)
{
    wave1->setVisible(state);
    replot();
}

void WaveWidget::show_wave2(int state)
{
    wave2->setVisible(state);
    replot();
}

void WaveWidget::getCurrentValues()
{
    wave1_amplitude = dataContainer->data[DataContainer::Wave1_Amp];
    wave1_frequency = dataContainer->data[DataContainer::Wave1_Freq];

    wave2_amplitude = dataContainer->data[DataContainer::Wave2_Amp];
    wave2_frequency = dataContainer->data[DataContainer::Wave2_Freq];

    phaseShift = dataContainer->data[DataContainer::PhaseShift];
    elapsedTime = dataContainer->data[DataContainer::ElapsedTime];
}
