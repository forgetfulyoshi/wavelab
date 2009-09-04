#ifndef VECTORWIDGET_H
#define VECTORWIDGET_H

#include <qwt_plot.h>

namespace Ui {
    class VectorWidget;
}

class DataContainer;
class VectorRender;

class VectorWidget : public QwtPlot {
    Q_OBJECT
public:

    VectorWidget(DataContainer *, QWidget *parent = 0);
    ~VectorWidget();

private:
    DataContainer * dataContainer;
    VectorRender * vectorRender;

public slots:
    void step();
    void reset();
    void show_wave1(int);
    void show_wave2(int);
};

#endif // VECTORWIDGET_H
