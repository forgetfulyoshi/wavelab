#include "datacontainer.h"

#define PI 3.14159

DataContainer::DataContainer(Ui::MainWindow * control): ui(control)
{
    data[Wave1_Amp]     = 0.0;
    data[Wave1_Freq]    = 0.0;
    data[Wave2_Amp]     = 0.0;
    data[Wave2_Freq]    = 0.0;
    data[PhaseShift]    = 0.0;
    data[ElapsedTime]   = 0.0;
}

void DataContainer::update()
{
    data[Wave1_Amp]     = ui->wave1_amplitude->value();
    data[Wave1_Freq]    = ui->wave1_frequency->value() * PI;
    data[Wave2_Amp]     = ui->wave2_amplitude->value();
    data[Wave2_Freq]    = ui->wave2_frequency->value() * PI;
    data[PhaseShift]    = ui->phaseShift->value() * PI;
    data[ElapsedTime]   += ui->time->value();
}

void DataContainer::resetTime()
{
    data[ElapsedTime] = 0.0;
}
