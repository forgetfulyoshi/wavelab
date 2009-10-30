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

#ifndef WAVEWIDGET_H
#define WAVEWIDGET_H

#include "labwidget.h"
#include <QVector>

class DataContainer;
class QwtPlotCurve;
class QwtPlotScaleItem;

class WaveWidget : public LabWidget {
    Q_OBJECT
public:
    WaveWidget(DataContainer *, QWidget * parent = 0);
    ~WaveWidget();

    virtual void setXScale(double);

public slots:
    virtual void step();
    virtual void reset();
    virtual void show_wave1(int);
    virtual void show_wave2(int);

private:
    void getCurrentValues();

    WaveWidget * wavePlot;

    QwtPlotCurve * wave1;
    QwtPlotCurve * wave2;
    QwtPlotCurve * supWave;

    QwtPlotScaleItem * xScale;
    QwtPlotScaleItem * yScale;

    QVector<double> wave1_y;
    QVector<double> wave2_y;
    QVector<double> supWave_y;
    QVector<double> x;

    double wave1_frequency;
    double wave1_amplitude;
    double wave2_frequency;
    double wave2_amplitude;
    double phaseShift;
    double elapsedTime;
};

#endif // WAVEWIDGET_H
