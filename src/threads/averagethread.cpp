/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#include "averagethread.h"

AverageThread::AverageThread(QObject *parent) : QThread(parent)
{
    av = new Averaging();
    mux = new QMutex();

    void (*progress)(int) = progressFunction;
    av->setProgressFunction(progress);
}

AverageThread::~AverageThread(){

}

void AverageThread::run(){
    mux->lock();
    qDebug() << "name: " << getName();
    mux->unlock();

    av->azimuthally();

    mux->lock();
    emit progressChanged(100);
    emit endProcessing(n);
    mux->unlock();
}


void AverageThread::setNutronData(NeutronData *neutron_data){
    av->setNeutronData(neutron_data);
}


void AverageThread::progressFunction(int value){
    QMutex mutex;
    mutex.lock();

    qDebug() << "average progress: " << value;

    mutex.unlock();

}
