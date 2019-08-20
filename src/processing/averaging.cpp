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
    progress(100);
}
