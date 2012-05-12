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

//------------------------------------------------------------------
// This class is used to maintain all data comming in from
// the UI and/or data to be used accross multiple widgets.
// This allows for the code to be kept a bit cleaner, and
// allows for a central location for data access / modification.
// All widgets have a pointer to the same DataContainer.
// There is admitedly the potential for concurency issues with this
// technique, but this is addressed via the use of QTimers
// (essentially threads).
//
// Data is accessed in the widgets via a pointer to data and the use
// of enumerated indices.
//-------------------------------------------------------------------

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
        NumSlits
            };

    double data[7];

    void update(); // Pull current values off the UI and modify any values as needed (i.e. increment ElapsedTime)
    void resetTime(); // Reset data[ElapsedTime] to 0.0

private:
    Ui::MainWindow * ui;

};

#endif // DATACONTAINER_H
