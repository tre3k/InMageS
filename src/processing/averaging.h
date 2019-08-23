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

    double getAngle(void){return a;}
    double getOpenAngle(void){return oa;}
    double getX0(void){return x0;}
    double getY0(void){return y0;}
    double getLength(void){return len;}
    double getOffset(void){return ofs;}

    int getResultSize(void){return result_size;}
    double *getResult(void){return result;}
    NeutronData *getNeutronData(void){return nd;}

    void azimuthally();

private:
    NeutronData *nd = nullptr;

    double oa = 120;             // open angle
    double a = 0;                // angle
    double x0 = 0.5;             // x0
    double y0 = 0.5;             // y0
    double ofs = 0;              // offsetb
    double len = 0.5;            // lenght


    int result_size = 0;
    double *result = nullptr;

private:
    /* progress function */
    void (*progress)(int) = nullptr;

};

#endif // AVERAGING_H
