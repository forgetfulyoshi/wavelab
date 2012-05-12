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
        phasor1(new QwtPlotCurve("Phasor 1")),
        phasor2(new QwtPlotCurve("Phasor 2")),
        sumVector(new QwtPlotCurve("Resultant Vector")),
        plotLine(new QwtPlotCurve("Plot Line")),
        phasor1_pen(new QPen(Qt::red)),
        phasor2_pen(new QPen(Qt::green)),
        sumVector_pen(new QPen(Qt::black)),
        plotLine_pen(new QPen(Qt::blue)),
        xScale(new QwtPlotScaleItem(QwtScaleDraw::BottomScale, frameWidth() / 2.0)),
        yScale(new QwtPlotScaleItem(QwtScaleDraw::LeftScale, frameWidth() / 2.0))
{    
    xScale->attach(this);
    enableAxis(QwtPlot::xBottom, false);

    yScale->attach(this);
    enableAxis(QwtPlot::yLeft, false);

    //-------------------------------
    // Modify line widths, 1 is normal
    phasor1_pen->setWidthF(1.5);
    phasor2_pen->setWidthF(1.5);
    sumVector_pen->setWidthF(1.5);
    plotLine_pen->setWidthF(1.5);
    //-------------------------------

    phasor1->setPen(*phasor1_pen);
    phasor2->setPen(*phasor2_pen);
    sumVector->setPen(*sumVector_pen);
    plotLine->setPen(*plotLine_pen);
}

VectorWidget::~VectorWidget()
{
    delete phasor1;
    delete phasor2;
    delete sumVector;
    delete plotLine;
    delete phasor1_pen;
    delete phasor2_pen;
    delete sumVector_pen;
    delete plotLine_pen;
    delete xScale;
    delete yScale;
}

void VectorWidget::step()
{
    reset();
    getCurrentValues();

    phasor1_x.append(yScale->position());
    phasor1_y.append(xScale->position());

    phasor1_x.append(wave1_amplitude * cos(wave1_frequency * elapsedTime));
    phasor1_y.append(wave1_amplitude * sin(wave1_frequency * elapsedTime));

    phasor2_x.append(phasor1_x.back());
    phasor2_y.append(phasor1_y.back());

    phasor2_x.append(phasor1_x.back() + wave2_amplitude * cos(wave2_frequency * elapsedTime + phaseShift));
    phasor2_y.append(phasor1_y.back() + wave2_amplitude * sin(wave2_frequency * elapsedTime + phaseShift));

    sumVector_x.append(yScale->position());
    sumVector_y.append(xScale->position());

    sumVector_x.append(phasor2_x.back());
    sumVector_y.append(phasor2_y.back());

    plotLine_x.append(sumVector_x.back());
    plotLine_y.append(sumVector_y.back());

    plotLine_x.append(this->frameSize().width());
    plotLine_y.append(plotLine_y.back());

    phasor1->setData(phasor2_x, phasor2_y); // Sorry, a little hackish, but it's the easiet way to flip the vectors
    phasor1->attach(this);

    phasor2->setData(phasor1_x, phasor1_y); // Sorry, a little hackish, but it's the easiet way to flip the vectors
    phasor2->attach(this);

    sumVector->setData(sumVector_x, sumVector_y);
    sumVector->attach(this);

    plotLine->setData(plotLine_x, plotLine_y);
    plotLine->attach(this);

    replot();
}

void VectorWidget::reset()
{
    phasor1_x.clear();
    phasor1_y.clear();
    phasor2_x.clear();
    phasor2_y.clear();
    sumVector_x.clear();
    sumVector_y.clear();
    plotLine_x.clear();
    plotLine_y.clear();

    phasor1->detach();
    phasor2->detach();
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

