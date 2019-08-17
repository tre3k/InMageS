/* mainwindow.h
 * Copyright 2019 14 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 * К. А. Пшеничный, Е. В. Алтынбаев, С. В. Григорьев
 * Расчет сечения рассеяния нейтронов на спиновых волнах в геликомагнетиках
 * ПОВЕРХНОСТЬ. РЕНТГЕНОВСКИЕ, СИНХРОТРОННЫЕ И НЕЙТРОННЫЕ ИССЛЕДОВАНИЯ N. 5 pp. 18–28 (Май 2018)
*/

#ifndef THEORY_H
#define THEORY_H

#include <math.h>
#include "neutrondata.h"

class Theory
{
public:
    Theory(NeutronData *neutron_data);
    ~Theory();

    /* in K */
    void setTemperature(double Temperature=300){T = Temperature;}

    /* for frromagnet phi=M_PI/4 for Helimagnet phi=M_PI/2 */
    void setAngleMagnetField(double angle=M_PI/4){phi = angle;}


    /* Field - megnetic field [T], ks - spiral wave vector [1/nm], Stiffness - spin-wave stiffness [meVA^2] */
    void calculateFerromagnet(double Field=0.0,double Stiffness=100.0);
    void calculateHelimagnet(double Field=0.0,double ks=0.01,double Stiffness=100.0);

    double getTheta0(void){return theta_0;}                 // theta_0
    double getThetaC2(void){return theta_C2;}               // theta_C^2
    double getThetaB(void){return theta_B;}                 // theta Bragg for Helimagnets

private:
    NeutronData *nd;                                        // neutron data

    double theta_0;
    double theta_C2;                                        // theta_C^2
    double theta_C;                                         // theta_C
    double theta_B;
    double T = 300;
    double phi = M_PI/4;                                    // angle of magnet field

private:
    void setConstantsFerromagnet(double Field,double Stiffness);                        // calculate theta_0,theta_C
    void setConstantsHelimagnet(double Field,double ks, double Stiffness);                        // calculate theta_0,theta_C
    void zeroND();
};

#endif // THEORY_H
