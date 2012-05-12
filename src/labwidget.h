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

//----------------------------------------------
// Abstract base class for all plotting widgets
// Inherits from QwtPlot
//----------------------------------------------

#ifndef LABWIDGET_H
#define LABWIDGET_H

#include <qwt_plot.h>

class DataContainer;

class LabWidget : public QwtPlot
{
    Q_OBJECT
public:
    LabWidget(DataContainer *, QWidget * placeholder = 0);
    virtual ~LabWidget();
    virtual void setYScale(double); // Default way to set range of the Y axis, rather than letting it automatically adujust
    virtual void setXScale(double); // Defaul way to set range of the X axis, rather than letting it automatically adujust

public slots:
    virtual void step() = 0;
    virtual void reset() = 0;
    virtual void show_wave1(int);
    virtual void show_wave2(int);

protected:
    DataContainer * dataContainer;

};

#endif // LABWIDGET_H
