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
