/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#ifndef AVERAGETHREAD_H
#define AVERAGETHREAD_H

#include <QThread>
#include <QMutex>
#include <QDebug>

#include "processing/averaging.h"
#include "processing/neutrondata.h"

class AverageThread : public QThread
{
    Q_OBJECT
public:
    AverageThread(QObject *parent = nullptr);
    ~AverageThread();
    void run() override;

    void setName(QString name){Name = name;}
    QString getName(){return Name;}

public:
    /* public averaging, this set angles,coord,etc */
    Averaging *av;

protected:
    QMutex *mux;

private:
    QString Name = "azimutal";

public slots:
    void setNutronData(NeutronData *neutron_data);

};

#endif // AVERAGETHREAD_H
