/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#ifndef AVERAGING_H
#define AVERAGING_H

#include <math.h>
#include "neutrondata.h"

class Averaging
{
public:
    Averaging(NeutronData *neutron_data = nullptr);
    ~Averaging();

    void setNeutronData(NeutronData *neturon_data){nd = neturon_data;}
    void setProgressFunction(void (*progressFunction)(int)){progress=progressFunction;}

    void azimuthally();

private:
    NeutronData *nd = nullptr;

    void (*progress)(int) = nullptr;

};

#endif // AVERAGING_H
