/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#include "neutrondata.h"


NeutronData::NeutronData(unsigned long x, unsigned long y)
{
    Nx = x;
    Ny = y;

    data_matrix = new Data2D(Nx,Ny);
}

NeutronData::~NeutronData(){
    delete data_matrix;
}

double NeutronData::get_ki(){
    return ki;
}

void NeutronData::update_ki_Ei(){
    ki = 2*M_PI/lambda;
    Ei = WaveVectorToImpulse(ki)*WaveVectorToImpulse(ki)/2/cmn();
}

double NeutronData::getEi_Joul(){
    return Ei;
}

double NeutronData::getEi_K(){
    return getEi_Joul()/ckB();
}

double NeutronData::getEi_meV(){
    return getEi_Joul()*1000/ce();
}


