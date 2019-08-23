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

    /* test */
    result_size = 1024;
    result = new double [result_size];

    for(int i=0;i<1024;i++){
        result[i]=i*i;
    }

    progress(100);
}
