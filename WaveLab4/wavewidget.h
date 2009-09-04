#ifndef WAVEWIDGET_H
#define WAVEWIDGET_H

#include <qwt_plot.h>

namespace Ui {
    class WaveWidget;
}

class DataContainer;
class WaveRender;

class WaveWidget : public QwtPlot {
    Q_OBJECT
public:
    WaveWidget(DataContainer *, QWidget * parent = 0);
    ~WaveWidget();

private:
    DataContainer * dataContainer;
    WaveRender * waveRender;

 public slots:
    void step();
    void reset();
    void show_wave1(int);
    void show_wave2(int);
};

#endif // WAVEWIDGET_H
