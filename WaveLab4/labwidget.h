#ifndef LABWIDGET_H
#define LABWIDGET_H

#include <qwt_plot.h>

class DataContainer;

class LabWidget : public QwtPlot
{
    Q_OBJECT
public:
    LabWidget(DataContainer *, QWidget * parent = 0);
    virtual ~LabWidget();

public slots:
    virtual void step() = 0;
    virtual void reset() = 0;
    virtual void show_wave1(int) = 0;
    virtual void show_wave2(int) = 0;

protected:
    DataContainer * dataContainer;

};

#endif // LABWIDGET_H
