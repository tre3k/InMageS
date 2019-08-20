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

    void setOpenAngle(double open_angle){oa = open_angle;}
    void setAngle(double angle){a = angle;}
    void setX0(double x){x0 = x;}
    void setY0(double y){y0 = y;}
    void setOffset(double offset){ofs = offset;}
    void setLenght(double lenght){len = lenght;}

    void azimuthally();

private:
    NeutronData *nd = nullptr;

    double oa;          // open angle
    double a;           // angle
    double x0;          // x0
    double y0;          // y0
    double ofs;         // offsetb
    double len;         // lenght



private:
    /* progress function */
    void (*progress)(int) = nullptr;

};

#endif // AVERAGING_H
