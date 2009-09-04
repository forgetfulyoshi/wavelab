#ifndef VECTORRENDER_H
#define VECTORRENDER_H

#include <QVector>

class DataContainer;
class VectorWidget;
class QwtPlotCurve;
class QwtPlotScaleItem;

class VectorRender
{
public:
    VectorRender(DataContainer *, VectorWidget *);
    ~VectorRender();

    void step();
    void reset();
    void show_wave1(int);
    void show_wave2(int);

private:
    void getCurrentValues();

    DataContainer * dataContainer;

    VectorWidget * vectorPlot;

    QwtPlotCurve * vector1;
    QwtPlotCurve * vector2;
    QwtPlotCurve * sumVector;

    QwtPlotScaleItem * xScale;
    QwtPlotScaleItem * yScale;

    QVector<double> vector1_x;
    QVector<double> vector1_y;
    QVector<double> vector2_x;
    QVector<double> vector2_y;
    QVector<double> sumVector_x;
    QVector<double> sumVector_y;

    double wave1_frequency;
    double wave1_amplitude;
    double wave2_frequency;
    double wave2_amplitude;
    double phaseShift;
    double elapsedTime;

};

#endif // VECTORRENDER_H
