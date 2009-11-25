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

#ifndef VECTORWIDGET_H
#define VECTORWIDGET_H

#include "labwidget.h"
#include <QVector>

class DataContainer;
class QwtPlotCurve;
class QwtPlotScaleItem;

class VectorWidget : public LabWidget {
    Q_OBJECT
public:

    VectorWidget(DataContainer *, QWidget *parent = 0);
    ~VectorWidget();

public slots:
    virtual void step(); // Advance the widget's animation by one frame
    virtual void reset(); // Reset the vector and clear corrosponding data

private:
    void getCurrentValues(); // Update local values from dataConainer

    QwtPlotCurve * sumVector; // Resultant vector of two phasors described via the gui input
    QwtPlotCurve * plotLine; // Blue line drawn horizontally from the tip of the sumVector to the right edge of the widget.
                             // Simulates a pen drawing the wave in the next widget

    QPen * sumVector_pen;
    QPen * plotLine_pen;

    QwtPlotScaleItem * xScale;
    QwtPlotScaleItem * yScale;

    QVector<double> sumVector_x;
    QVector<double> sumVector_y;
    QVector<double> plotLine_x;
    QVector<double> plotLine_y;

    double wave1_frequency;
    double wave1_amplitude;
    double wave2_frequency;
    double wave2_amplitude;
    double phaseShift;
    double elapsedTime;
};

#endif // VECTORWIDGET_H
