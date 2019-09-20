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

    double dphi,dr;                                     // small values for incriminate
    double r,phi,x=0.0,y=0.0;                           // variables
    int n,i;                                              // counter for average
    double S;

    int max_pixel_count = nd->data_matrix->size_x();
    if(max_pixel_count < nd->data_matrix->size_y()) max_pixel_count = nd->data_matrix->size_y();

    int px0 = DoubleToInt((0.5+x0/2)*max_pixel_count);          // x0, y0 in pixels
    int py0 = DoubleToInt((0.5+y0/2)*max_pixel_count);

    double R = len*max_pixel_count/2;       // len
    double OFS = ofs*max_pixel_count/2;     // offset

    qDebug() << "R: " << R << " offset: " << OFS;

    dr = sqrt(2); i = 0;
    result_size = DoubleToInt((R-OFS)/dr);
    result = new double[result_size+1];
    for(r=OFS; r<R; r+=dr){
        dphi = atan(dr/r);
        n = 0;
        S=0;
        for(phi=a-oa/2; phi<a+oa/2; phi+=dphi){
            //qDebug() << "r: " << r << " phi: " << phi;
            toDecart(r,phi,&x,&y);
            //qDebug() << "x: " << DoubleToInt(x+px0) << "y: " << DoubleToInt(y+py0);
            S += nd->data_matrix->at(DoubleToInt(x+px0),DoubleToInt(y+py0));
            n++;
        }
        result[i] = S/n;
        i++;
    }

    qDebug() << result_size << " " << i;

    progress(100);
}
