#include "labwidget.h"
#include "datacontainer.h"

LabWidget::LabWidget(DataContainer * d, QWidget * parent):
        dataContainer(d)
{
    setParent(parent);
}

LabWidget::~LabWidget()
{

}

void LabWidget::setYScale(double range)
{
    this->setAxisAutoScale(0);
    this->setAxisScale(0,-range, range);
}

void LabWidget::setXScale(double range)
{
    this->setAxisAutoScale(2);
    this->setAxisScale(2, -range, range);
}

void LabWidget::show_wave1(int)
{

}

void LabWidget::show_wave2(int)
{

}
