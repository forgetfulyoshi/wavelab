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
