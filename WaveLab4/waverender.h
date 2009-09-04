#ifndef WAVERENDER_H
#define WAVERENDER_H

#include <QVector>

class DataContainer;
class WaveWidget;
class QwtPlotCurve;

class WaveRender
{
public:
    WaveRender(DataContainer *, WaveWidget *);
    ~WaveRender();

    void step();
    void reset();
    void show_wave1(int);
    void show_wave2(int);

private:
    void getCurrentValues();

    DataContainer * dataContainer;
    WaveWidget * wavePlot;

    QwtPlotCurve * wave1;
    QwtPlotCurve * wave2;
    QwtPlotCurve * supWave;

    QVector<double> wave1_y;
    QVector<double> wave2_y;
    QVector<double> supWave_y;
    QVector<double> x;

    double wave1_frequency;
    double wave1_amplitude;
    double wave2_frequency;
    double wave2_amplitude;
    double phaseShift;
    double elapsedTime;
};

#endif // WAVERENDER_H
