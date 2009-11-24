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

#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include "ui_mainwindow.h"

class DataContainer
{

public:
    DataContainer(Ui::MainWindow *);

    enum Data
    {
        Wave1_Amp, Wave1_Freq, Wave2_Amp, Wave2_Freq, PhaseShift, ElapsedTime,
        NumSlits,
            };

    double data[11];

    void update();
    void resetTime();

private:
    Ui::MainWindow * ui;

};

#endif // DATACONTAINER_H
