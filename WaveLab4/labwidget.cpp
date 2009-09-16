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
    setAxisScale(0,-range, range);
}

void LabWidget::setXScale(double range)
{
    setAxisScale(2, -range, range);
}

void LabWidget::show_wave1(int)
{

}

void LabWidget::show_wave2(int)
{

}
