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

#include "vectorwidget.h"

#include "datacontainer.h"
#include "vectorrender.h"

VectorWidget::VectorWidget(DataContainer * d, QWidget *parent) :
    dataContainer(d)
{
    setParent(parent);

    vectorRender = new VectorRender(dataContainer, this);
}

VectorWidget::~VectorWidget()
{
    delete vectorRender;
}

void VectorWidget::step()
{
    vectorRender->step();
}

void VectorWidget::reset()
{
    vectorRender->reset();
}

void VectorWidget::show_wave1(int state)
{
    vectorRender->show_wave1(state);
}

void VectorWidget::show_wave2(int state)
{
    vectorRender->show_wave2(state);
}
