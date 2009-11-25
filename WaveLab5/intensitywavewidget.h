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

#ifndef INTENSITYWAVEWIDGET_H
#define INTENSITYWAVEWIDGET_H

#include "labwidget.h"
#include <QVector>

class DataContainer;
class QwtPlotCurve;
class QwtPlotScaleItem;

class IntensityWaveWidget : public LabWidget {

public:
    IntensityWaveWidget(DataContainer * d, QWidget * parent = 0);
    ~IntensityWaveWidget();

    virtual void setXScale(double); // Overriding LabWidget method, parameter ignored
    virtual void setYScale(double); // Overriding LabWidget method, parameter ignored

public slots:
    virtual void step(); // Advance widget animation by one frame
    virtual void reset(); // Reset all lines and clear corrosponding data

private:
    void getCurrentValues(); // Update local values from dataContainer

    QwtPlotCurve * intWave; // Red line, Intensity (or Amplitude squared) as a function of phase angle (delta)
    QwtPlotCurve * intTrace; // Blue line, gives tracing effect to the wave, also Intensity as a function of delta

    QPen * intWave_pen;
    QPen * intTrace_pen;

    QwtPlotScaleItem * xScale;
    QwtPlotScaleItem * yScale;

    QVector<double> intWave_x;
    QVector<double> intWave_y;
    QVector<double> intTrace_x;
    QVector<double> intTrace_y;

    double numSlits;
    double delta;
    double amp;

};

#endif // INTENSITYWAVEWIDGET_H
