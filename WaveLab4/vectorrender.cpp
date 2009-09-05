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

#include "vectorrender.h"
#include "datacontainer.h"
#include "vectorwidget.h"

#include <cmath>
#include <qwt_plot_curve.h>
#include <qwt_plot_scaleitem.h>

VectorRender::VectorRender(DataContainer * d, VectorWidget * v)
{
    dataContainer = d;
    vectorPlot = v;

    vector1 = new QwtPlotCurve("Vector A");
    vector2 = new QwtPlotCurve("Vector B");
    sumVector = new QwtPlotCurve("Resultant Vector");


    xScale = new QwtPlotScaleItem(QwtScaleDraw::BottomScale, vectorPlot->frameWidth() / 2.0);
    yScale = new QwtPlotScaleItem(QwtScaleDraw::LeftScale, vectorPlot->frameWidth() / 2.0);



    xScale->attach(vectorPlot);
    vectorPlot->enableAxis(QwtPlot::xBottom, false);

    yScale->attach(vectorPlot);
    vectorPlot->enableAxis(QwtPlot::yLeft, false);

}

VectorRender::~VectorRender()
{
    delete vector1;
    delete vector2;
    delete sumVector;

    delete xScale;
    delete yScale;
}

void VectorRender::step()
{
    reset();
    getCurrentValues();

    vector1_x.append(0.0 + yScale->position());
    vector1_y.append(0.0 + xScale->position());

    vector1_x.append(wave1_amplitude * cos(wave1_frequency * elapsedTime) + yScale->position());
    vector1_y.append(wave1_amplitude * sin(wave1_frequency * elapsedTime) + xScale->position());

    vector2_x.append(vector1_x.back());
    vector2_y.append(vector1_y.back());

    vector2_x.append(wave2_amplitude * cos(wave2_frequency * elapsedTime + phaseShift) + vector1_x.front());
    vector2_y.append(wave2_amplitude * sin(wave2_frequency * elapsedTime + phaseShift) + vector1_y.front());

    sumVector_x.append(vector1_x.front());
    sumVector_y.append(vector1_y.front());

    sumVector_x.append(vector2_x.back());
    sumVector_y.append(vector2_y.back());

    vector1->setData(vector1_x, vector1_y);
    vector1->setPen(QColor(Qt::green));
    vector1->attach(vectorPlot);

    vector2->setData(vector2_x, vector2_y);
    vector2->setPen(QColor(Qt::red));
    vector2->attach(vectorPlot);

    sumVector->setData(sumVector_x, sumVector_y);
    sumVector->setPen(QColor(Qt::black));
    sumVector->attach(vectorPlot);

    vectorPlot->replot();
}

void VectorRender::reset()
{
    vector1_x.clear();
    vector1_y.clear();
    vector2_x.clear();
    vector2_y.clear();
    sumVector_x.clear();
    sumVector_y.clear();

    vector1->detach();
    vector2->detach();
    sumVector->detach();

    vectorPlot->replot();
}

void VectorRender::show_wave1(int state)
{
    vector1->setVisible(state);
    vectorPlot->replot();
}

void VectorRender::show_wave2(int state)
{
    vector2->setVisible(state);
    vectorPlot->replot();
}

void VectorRender::getCurrentValues()
{
    wave1_amplitude = dataContainer->data[DataContainer::Wave1_Amp];
    wave1_frequency = dataContainer->data[DataContainer::Wave1_Freq];

    wave2_amplitude = dataContainer->data[DataContainer::Wave2_Amp];
    wave2_frequency = dataContainer->data[DataContainer::Wave2_Freq];

    phaseShift = dataContainer->data[DataContainer::PhaseShift];
    elapsedTime = dataContainer->data[DataContainer::ElapsedTime];

    vectorPlot->setAxisScale(QwtPlot::yLeft, -(wave1_amplitude + wave2_amplitude) * 0.75 , (wave1_amplitude + wave2_amplitude) * 0.75, 0);
    vectorPlot->setAxisScale(QwtPlot::xBottom, -(wave1_amplitude + wave2_amplitude) * 0.75 , (wave1_amplitude + wave2_amplitude) * 0.75, 0);
}
