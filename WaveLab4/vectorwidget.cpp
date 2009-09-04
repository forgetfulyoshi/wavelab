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
