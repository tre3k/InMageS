#include "theory.h"

Theory::Theory(NeutronData *neutron_data)
{
    nd = neutron_data;
}

Theory::~Theory(){

}

void Theory::setConstantsFerromagnet(double Field, double Stiffness){
    theta_0 = nd->getEi_meV()/
              nd->get_ki_A()/
              nd->get_ki_A()/
              Stiffness;
    theta_C2 = theta_0*theta_0 - nd->cgf()*nd->cub()*Field*theta_0/nd->getEi_Joul();
    if(theta_C2>=0){
        theta_C = sqrt(theta_C2);
    }else{
        theta_C = 0.0;
    }
}

void Theory::setConstantsHelimagnet(double Field, double ks, double Stiffness){
    setConstantsFerromagnet(Field,Stiffness);
    theta_B = ks/nd->get_ki_nm();
}

void Theory::calculateFerromagnet(double Field, double Stiffness){
    double I;
    double theta_x, theta_y, theta, theta2;

    const double dtheta_x = 2*nd->getMaximumThetaX()/nd->size_Nx();
    const double dtheta_y = 2*nd->getMaximumThetaY()/nd->size_Ny();

    const double guH = nd->cgf()*nd->cub()*Field;

    setConstantsFerromagnet(Field, Stiffness);

    theta_x = - nd->getMaximumThetaX();
    theta_y = - nd->getMaximumThetaY();

    zeroND();
    setAngleMagnetField(M_PI/4);

    for(unsigned long int i=0;i<nd->size_Nx();i++){
        theta_x += dtheta_x;
        theta_y = - nd->getMaximumThetaY();
        for(unsigned long int j=0;j<nd->size_Ny();j++){
            theta_y += dtheta_y;

            theta = theta_x + theta_y;
            theta2 = theta_x*theta_x + theta_y*theta_y;

            I = (T/nd->getEi_K())*sin(2*phi)*(
                        (theta_0*theta_0-guH)*theta_x*theta_0/
                        sqrt(theta_0*theta_0 - theta2 - guH)/
                        (theta2*theta_0*theta_0 + guH*guH)
                  );
            if((theta_0*theta_0-theta2-guH) <=0 ) I=0.0;

            nd->data_matrix->set(i,j,I);
        }
    }

}

void Theory::calculateHelimagnet(double Field, double ks, double Stiffness){
    double I;
    double theta_x, theta_y, theta, theta2;
    double G1,G2,G3,G4,F1,F2,F3,F4,w1,w2,w3,w4,sqr1,sqr2,sqr3,sqr4;     // tmp variables for calculation


    const double dtheta_x = 2*nd->getMaximumThetaX()/nd->size_Nx();
    const double dtheta_y = 2*nd->getMaximumThetaY()/nd->size_Ny();

    const double guH = nd->cgf()*nd->cub()*Field;

    setConstantsHelimagnet(Field, ks, Stiffness);


    theta_x = - nd->getMaximumThetaX();
    theta_y = - nd->getMaximumThetaY();

    zeroND();

    for(unsigned long int i=0;i<nd->size_Nx();i++){
        theta_x += dtheta_x;
        theta_y = - nd->getMaximumThetaY();
        for(unsigned long int j=0;j<nd->size_Ny();j++){
            theta_y += dtheta_y;

            theta = theta_x + theta_y;
            theta2 = theta_x*theta_x + theta_y*theta_y;

            sqr1 = (theta_C2-(theta_x-theta_B)*(theta_x-theta_B)-theta_y*theta_y);
            sqr2 = (theta_C2-(theta_x-theta_B)*(theta_x-theta_B)-theta_y*theta_y);
            w1 = theta_0 + sqrt(sqr1);
            w2 = theta_0 - sqrt(sqr2);
            G1 = (1/w1)*theta_x*theta_x/(theta_x*theta_x+theta_y*theta_y+w1*w1);
            G2 = (1/w2)*theta_x*theta_x/(theta_x*theta_x+theta_y*theta_y+w2*w2);
            F1 = 1-(1/theta_0)*w1;
            F2 = 1-(1/theta_0)*w2;
            sqr3 = (theta_C2-(theta_x+theta_B)*(theta_x+theta_B)-theta_y*theta_y);
            sqr4 = (theta_C2-(theta_x+theta_B)*(theta_x+theta_B)-theta_y*theta_y);
            w3 = -theta_0 + sqrt(sqr3);
            w4 = -theta_0 - sqrt(sqr4);
            G3 = (1/w3)*theta_x*theta_x/(theta_x*theta_x+theta_y*theta_y+w3*w3);
            G4 = (1/w4)*theta_x*theta_x/(theta_x*theta_x+theta_y*theta_y+w4*w4);
            F3 = 1+(1/theta_0)*w3;
            F4 = 1+(1/theta_0)*w4;

            I = 0.0;
            if(sqr1>0) I+=G1/F1;
            if(sqr2>0) I+=G2/F2;
            if(sqr3>0) I+=G3/F3;
            if(sqr4>0) I+=G4/F4;
            I *= (T/nd->getEi_K());

            nd->data_matrix->set(i,j,I);
        }
    }
}


void Theory::zeroND(){
     for(unsigned long int i=0;i<nd->size_Nx();i++){
         for(unsigned long int j=0;j<nd->size_Ny();j++){
             nd->data_matrix->set(i,j,0.0);
         }
     }
}

