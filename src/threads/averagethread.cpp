#include "averagethread.h"

AverageThread::AverageThread(QObject *parent) : QThread(parent)
{
    av = new Averaging();
    mux = new QMutex();
}

AverageThread::~AverageThread(){

}

void AverageThread::run(){

}


void AverageThread::setNutronData(NeutronData *neutron_data){
    av->setNeutronData(neutron_data);
}
