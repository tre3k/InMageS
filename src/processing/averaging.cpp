/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#include "averaging.h"

Averaging::Averaging(NeutronData *neutron_data)
{
    setNeutronData(neutron_data);

}

Averaging::~Averaging(){

}

void Averaging::azimuthally(){
    if(result!=nullptr) delete result;
    if(nd==nullptr) return;

    /* test */
    result_size = nd->size_Nx();
    result = new double [result_size];

    for(int i=0;i<result_size;i++){
        result[i]=i*i*a;
    }

    progress(100);
}
