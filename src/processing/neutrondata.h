/* mainwindow.h
 * Copyright 2019 14 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */


#ifndef NEUTRONDATA_H
#define NEUTRONDATA_H

#include <math.h>
#include "data2d.h"

class NeutronData
{
public:
    NeutronData(unsigned long x=0, unsigned long y=0);
    ~NeutronData();
    /* if you now lamda */
    void update_ki_Ei(void);
    /* if you now theta_max_x and Nx */
    void update_D(void);        // calculate Distance soure to detector

    double get_ki();

    double getEi_Joul(void);                                        // Joul
    double getEi_meV(void);                                         // meV
    double getEi_K(void);                                           // Kelvin

    static double cPlank(){return 6.626070040e-34;}                 // Plank constant   [Joul*s]
    static double ce(){return 1.60217662e-19;}                      // electron         [Kulon]
    static double cmn(){return 1.67492749804e-27;}                  // mass neutron     [kg]
    static double ckB(){return 1.3806504e-23;}                      // Bolzman constatn

    static double WaveVectorToImpulse(double value){                // value in [1/Angstorm]
        return cPlank()*value*1e+10;
    }

    unsigned long size_Nx(void);
    unsigned long size_Ny(void);

public:
    double D;               // distance soruce to detetctor                      [m]
    double Ly;              // size of detetcotor (size of pixel * resolution)   [m]
    double Lx;
    double px;              // size of pixel                                     [mm]
    double py;
    double theta_max_x;     // maximum theta                                     [mrad]
    double theta_max_y;
    double wave_vector_max_x;   // transmission maximum wavevector               [1/Angstrom]
    double wave_vector_max_y;
    double lambda;          // wave length of neutron                            [Angstrom 1e-10m]

    Data2D *data_matrix;

private:
    double ki;              // incedent wave vector neutron                      [1/Angstrom]
    double Ei;              // incedent energy neutron                           [Joul]

    unsigned long Nx, Ny;

};



#endif // NEUTRONDATA_H
