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

#include "vectorwidget.h"
#include "datacontainer.h"

#include <cmath>
#include <qwt_plot_curve.h>
#include <qwt_plot_scaleitem.h>

VectorWidget::VectorWidget(DataContainer * d, QWidget *parent) :
        LabWidget(d, parent),
        sumVector(new QwtPlotCurve("Resultant Vector")),
        plotLine(new QwtPlotCurve("Plot Line")),
        xScale(new QwtPlotScaleItem(QwtScaleDraw::BottomScale, frameWidth() / 2.0)),
        yScale(new QwtPlotScaleItem(QwtScaleDraw::LeftScale, frameWidth() / 2.0))
{    
    xScale->attach(this);
    enableAxis(QwtPlot::xBottom, false);

    yScale->attach(this);
    enableAxis(QwtPlot::yLeft, false);
}

VectorWidget::~VectorWidget()
{
    delete sumVector;
    delete plotLine;
    delete xScale;
    delete yScale;
}

void VectorWidget::step()
{
    reset();
    getCurrentValues();

    vector1_x.append(0.0 + yScale->position());
    vector1_y.append(0.0 + xScale->position());

    vector1_x.append(wave1_amplitude * cos(wave1_frequency * elapsedTime) + vector1_x.front());
    vector1_y.append(wave1_amplitude * sin(wave1_frequency * elapsedTime) + vector1_y.front());

    vector2_x.append(vector1_x.back());
    vector2_y.append(vector1_y.back());

    vector2_x.append(wave2_amplitude * cos(wave2_frequency * elapsedTime + phaseShift) + vector2_x.front());
    vector2_y.append(wave2_amplitude * sin(wave2_frequency * elapsedTime + phaseShift) + vector2_y.front());

    sumVector_x.append(vector1_x.front());
    sumVector_y.append(vector1_y.front());

    sumVector_x.append(vector2_x.back());
    sumVector_y.append(vector2_y.back());

    plotLine_x.append(sumVector_x.back());
    plotLine_y.append(sumVector_y.back());

    plotLine_x.append(this->frameSize().width());
    plotLine_y.append(plotLine_y.back());

    sumVector->setData(sumVector_x, sumVector_y);
    sumVector->setPen(QColor(Qt::black));
    sumVector->attach(this);

    plotLine->setData(plotLine_x, plotLine_y);
    plotLine->setPen(QColor(Qt::blue));
    plotLine->attach(this);

    replot();
}

void VectorWidget::reset()
{
    vector1_x.clear();
    vector1_y.clear();
    vector2_x.clear();
    vector2_y.clear();
    sumVector_x.clear();
    sumVector_y.clear();
    plotLine_x.clear();
    plotLine_y.clear();

    sumVector->detach();
    plotLine->detach();

    replot();
}

void VectorWidget::getCurrentValues()
{
    wave1_amplitude = dataContainer->data[DataContainer::Wave1_Amp];
    wave1_frequency = dataContainer->data[DataContainer::Wave1_Freq];

    wave2_amplitude = dataContainer->data[DataContainer::Wave2_Amp];
    wave2_frequency = dataContainer->data[DataContainer::Wave2_Freq];

    phaseShift = dataContainer->data[DataContainer::PhaseShift];
    elapsedTime = dataContainer->data[DataContainer::ElapsedTime];
}
