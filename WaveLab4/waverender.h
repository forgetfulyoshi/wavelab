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

#ifndef WAVERENDER_H
#define WAVERENDER_H

#include <QVector>

class DataContainer;
class WaveWidget;
class QwtPlotCurve;

class WaveRender
{
public:
    WaveRender(DataContainer *, WaveWidget *);
    ~WaveRender();

    void step();
    void reset();
    void show_wave1(int);
    void show_wave2(int);

private:
    void getCurrentValues();

    DataContainer * dataContainer;
    WaveWidget * wavePlot;

    QwtPlotCurve * wave1;
    QwtPlotCurve * wave2;
    QwtPlotCurve * supWave;

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

#endif // WAVERENDER_H
