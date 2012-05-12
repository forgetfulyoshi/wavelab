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

#ifndef INTENSITYVECTORWIDGET_H
#define INTENSITYVECTORWIDGET_H

#include "labwidget.h"
#include <QVector>

class DataContainer;
class QwtPlotCurve;
class QwtPlotScaleItem;

class IntensityVectorWidget : public LabWidget
{

public:
    IntensityVectorWidget(DataContainer * d, QWidget * parent = 0);
    ~IntensityVectorWidget();

public slots:
    virtual void step(); // Advance widget's animation by one frame
    virtual void reset(); // Reset phasors/vectors and clear corrosponding data

private:
    void getCurrentValues(); // Update local values from dataContainer
    void clear(); // Used internally in place of reset, allows for a refresh without clearing delta

    QwtPlotCurve * intensityPhasor;
    QwtPlotCurve * resultantVector;

    QPen * intensityPhasor_pen;
    QPen * resultantVector_pen;

    QwtPlotScaleItem * xScale;
    QwtPlotScaleItem * yScale;

    QVector<double> intensity_x;
    QVector<double> intensity_y;
    QVector<double> resultant_x;
    QVector<double> resultant_y;

    double numSlits;
    double delta;
};

#endif // INTENSITYVECTORWIDGET_H
