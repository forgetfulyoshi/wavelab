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

#include "intensitywavewidget.h"
#include "datacontainer.h"

#include <cmath>
#include <qcolor.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_scaleitem.h>

#define PI 3.14159
#define CONVERSION_FACT 0.0175 // Convert degrees to radians

IntensityWaveWidget::IntensityWaveWidget(DataContainer * d, QWidget * p):
        LabWidget(d, p),
        intWave(new QwtPlotCurve("Intensity Wave")),
        xScale(new QwtPlotScaleItem(QwtScaleDraw::BottomScale)),
        yScale(new QwtPlotScaleItem(QwtScaleDraw::RightScale)),
        delta(0)
{
    xScale->attach(this);
    enableAxis(QwtPlot::xBottom, false);

    yScale->attach(this);
    enableAxis(QwtPlot::yLeft, false);
}

IntensityWaveWidget::~IntensityWaveWidget()
{
    intWave->detach();

    delete intWave;
}

void IntensityWaveWidget::setXScale(double)
{
    setAxisScale(2, 0.0, 720);
}

void IntensityWaveWidget::setYScale(double)
{
    setAxisScale(0, 0.0, dataContainer->data[DataContainer::NumSlits] * dataContainer->data[DataContainer::NumSlits]);
}

void IntensityWaveWidget::step()
{
    getCurrentValues();
    if (delta < 719) {

        intWave_x.append(delta);

        if (delta < 1) {
            intWave_y.append(numSlits * numSlits);
        } else {
            amp = sin(numSlits * delta * CONVERSION_FACT * 0.5) / sin(delta * CONVERSION_FACT * 0.5);
            intWave_y.append(amp * amp);
        }

        intWave->setData(intWave_x, intWave_y);
        intWave->setPen(QColor(Qt::blue));
        intWave->attach(this);

        replot();
    }
}

void IntensityWaveWidget::reset()
{
    intWave_x.clear();
    intWave_y.clear();

    intWave->detach();

    delta = 0.0;

    replot();
}

void IntensityWaveWidget::getCurrentValues()
{
    numSlits = dataContainer->data[DataContainer::NumSlits];
    delta++;
}
