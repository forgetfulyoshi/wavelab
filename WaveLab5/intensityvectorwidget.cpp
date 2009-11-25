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

#include "intensityvectorwidget.h"
#include "datacontainer.h"

#include <cmath>
#include <qwt_plot_curve.h>
#include <qwt_plot_scaleitem.h>

#define PI 3.14159
#define CONVERSION_FACT 0.0175 // Convert degrees to radians

IntensityVectorWidget::IntensityVectorWidget(DataContainer * d, QWidget * p):
        LabWidget(d, p),
        intensityPhasor(new QwtPlotCurve("Intensity Phasor")),
        resultantVector(new QwtPlotCurve("Resultant Vector")),
        xScale(new QwtPlotScaleItem(QwtScaleDraw::BottomScale, frameWidth() / 2.0)),
        yScale(new QwtPlotScaleItem(QwtScaleDraw::LeftScale, frameWidth() / 2.0)),
        delta(0)
{
    xScale->attach(this);
    enableAxis(QwtPlot::xBottom, false);

    yScale->attach(this);
    enableAxis(QwtPlot::yLeft, false);
}

IntensityVectorWidget::~IntensityVectorWidget()
{
    delete intensityPhasor;
    delete resultantVector;
    delete xScale;
    delete yScale;
}

void IntensityVectorWidget::step()
{

    if (delta < 719) {

        double x = yScale->position();
        double y = xScale->position();

        clear();
        getCurrentValues();

        intensity_x.append(x);
        intensity_y.append(y);

        resultant_x.append(x);
        resultant_y.append(y);

        for (int i = 0; i < numSlits; i++) {
            x += cos(i * delta * CONVERSION_FACT);
            y += sin(i * delta * CONVERSION_FACT);

            intensity_x.append(x);
            intensity_y.append(y);
        }

        resultant_x.append(x);
        resultant_y.append(y);

        QPen int_pen = QPen(QColor(Qt::red));
        int_pen.setWidth(2);
        intensityPhasor->setData(intensity_x, intensity_y);
        intensityPhasor->setPen(int_pen);
        intensityPhasor->attach(this);

        QPen res_pen = QPen(QColor(Qt::blue));
        res_pen.setWidth(2);
        resultantVector->setData(resultant_x, resultant_y);
        resultantVector->setPen(res_pen);
        resultantVector->attach(this);

        replot();
        delta += 1.0;
    }
}

void IntensityVectorWidget::reset()
{
    clear();
    delta = 0.0;
}

void IntensityVectorWidget::clear()
{
    intensity_x.clear();
    intensity_y.clear();

    resultant_x.clear();
    resultant_y.clear();

    intensityPhasor->detach();
    resultantVector->detach();

    replot();
}

void IntensityVectorWidget::getCurrentValues()
{
    numSlits = dataContainer->data[DataContainer::NumSlits];
}
