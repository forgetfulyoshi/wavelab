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

#include "wavewidget.h"

#include "datacontainer.h"
#include "waverender.h"

WaveWidget::WaveWidget(DataContainer * d, QWidget * parent) :
    dataContainer(d)
{
    setParent(parent);

    waveRender = new WaveRender(dataContainer, this);

    setAxisTitle(0, "Displacement");
    setAxisTitle(2, "Time");
}

WaveWidget::~WaveWidget()
{
    delete waveRender;
}

void WaveWidget::step()
{
    waveRender->step();
}

void WaveWidget::reset()
{
   waveRender->reset();
}

void WaveWidget::show_wave1(int state)
{
    waveRender->show_wave1(state);
}

void WaveWidget::show_wave2(int state)
{
    waveRender->show_wave2(state);
}
