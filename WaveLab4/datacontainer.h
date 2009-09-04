#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include "ui_mainwindow.h"

class DataContainer
{

public:
    DataContainer(Ui::MainWindow *);

    enum Data
    {
        Wave1_Amp, Wave1_Freq, Wave2_Amp, Wave2_Freq, PhaseShift, ElapsedTime
            };

    double data[6];

    void update();
    void resetTime();

private:
    Ui::MainWindow * ui;

};

#endif // DATACONTAINER_H
