#include "waverender.h"

#include <cmath>
#include <qcolor.h>
#include "wavewidget.h"
#include <qwt_plot_curve.h>
#include "datacontainer.h"

WaveRender::WaveRender(DataContainer * d, WaveWidget * w)
{
    dataContainer = d;
    wavePlot = w;

    wave1 = new QwtPlotCurve("Wave 1");
    wave2 = new QwtPlotCurve("Wave 2");
    supWave = new QwtPlotCurve("Superposition Wave");
}

WaveRender::~WaveRender()
{
    wave1->detach();
    wave2->detach();
    supWave->detach();

    delete wave1;
    delete wave2;
    delete supWave;
}

void WaveRender::step()
{

    getCurrentValues();

    x.append(elapsedTime);
    wave1_y.append(wave1_amplitude * sin(wave1_frequency * elapsedTime));
    wave2_y.append(wave2_amplitude * sin(wave2_frequency * elapsedTime + phaseShift));
    supWave_y.append(wave1_y.back() + wave2_y.back());

    // Set the data and attach Wave 1 to the graph
    wave1->setData(x, wave1_y);
    wave1->setPen(QColor(Qt::green));
    wave1->attach(wavePlot);

    // Set the data and attach Wave 2 to the graph
    wave2->setData(x, wave2_y);
    wave2->setPen(QColor(Qt::red));
    wave2->attach(wavePlot);

    // Set the data and attach the Superposition wave to the graph
    supWave->setData(x, supWave_y);
    supWave->setPen(QColor(Qt::black));
    supWave->attach(wavePlot);

    // Update the graph with new data
    wavePlot->replot();

}

void WaveRender::show_wave1(int state)
{
    wave1->setVisible(state);
    wavePlot->replot();
}

void WaveRender::show_wave2(int state)
{
    wave2->setVisible(state);
    wavePlot->replot();
}

void WaveRender::reset()
{
    wave1_y.clear();
    wave2_y.clear();
    supWave_y.clear();
    x.clear();

    wave1->detach();
    wave2->detach();
    supWave->detach();

    wavePlot->replot();
}

void WaveRender::getCurrentValues()
{
    wave1_amplitude = dataContainer->data[DataContainer::Wave1_Amp];
    wave1_frequency = dataContainer->data[DataContainer::Wave1_Freq];

    wave2_amplitude = dataContainer->data[DataContainer::Wave2_Amp];
    wave2_frequency = dataContainer->data[DataContainer::Wave2_Freq];

    phaseShift = dataContainer->data[DataContainer::PhaseShift];
    elapsedTime = dataContainer->data[DataContainer::ElapsedTime];
}
