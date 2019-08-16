#include "theory.h"

Theory::Theory(NeutronData *neutron_data)
{
    nd = neutron_data;
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
    theta_0 = nd->getEi_meV()/
              nd->get_ki_A()/
              nd->get_ki_A()/
              Stiffness;
    theta_C2 = 0.0;
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
    setConstantsHelimagnet(Field, ks, Stiffness);
}


void Theory::zeroND(){
     for(unsigned long int i=0;i<nd->size_Nx();i++){
         for(unsigned long int j=0;j<nd->size_Ny();j++){
             nd->data_matrix->set(i,j,0.0);
         }
     }
}

