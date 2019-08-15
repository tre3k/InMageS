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

double NeutronData::get_ki_A(){
    return ki*1e-10;
}

double NeutronData::get_ki_nm(){
    return ki*1e-9;
}

void NeutronData::update_ki_Ei(){
    ki = 2.0*M_PI/lambda/1e-10;
    Ei = WaveVectorToImpulse(ki)*WaveVectorToImpulse(ki)/2.0/cmn();
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

unsigned long int NeutronData::size_Nx(){
    return Nx;
}

unsigned long int NeutronData::size_Ny(){
    return Ny;
}
