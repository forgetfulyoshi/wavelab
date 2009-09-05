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

#include "datacontainer.h"

#define PI 3.14159

DataContainer::DataContainer(Ui::MainWindow * control): ui(control)
{
    data[Wave1_Amp]     = 0.0;
    data[Wave1_Freq]    = 0.0;
    data[Wave2_Amp]     = 0.0;
    data[Wave2_Freq]    = 0.0;
    data[PhaseShift]    = 0.0;
    data[ElapsedTime]   = 0.0;
}

void DataContainer::update()
{
    data[Wave1_Amp]     = ui->wave1_amplitude->value();
    data[Wave1_Freq]    = ui->wave1_frequency->value() * PI;
    data[Wave2_Amp]     = ui->wave2_amplitude->value();
    data[Wave2_Freq]    = ui->wave2_frequency->value() * PI;
    data[PhaseShift]    = ui->phaseShift->value() * PI;
    data[ElapsedTime]   += ui->time->value();
}

void DataContainer::resetTime()
{
    data[ElapsedTime] = 0.0;
}
