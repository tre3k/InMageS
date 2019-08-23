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
#include "widgets/statusbar.h"

class AverageThread : public QThread
{
    Q_OBJECT
public:
    AverageThread(QObject *parent = nullptr);
    ~AverageThread();
    void run() override;

    void setName(QString name){Name = name;}
    QString getName(){return Name;}


    int getNumber(void){return n;}
    void setNumber(int number){n = number;}

public:
    /* public averaging, this set angles,coord,etc */
    Averaging *av;

protected:
    QMutex *mux;
    /* number of thread */
    int n = 0;

private:
    QString Name = "azimutal";
    static void progressFunction(int value);


signals:
    void progressChanged(int);
    /* send id number of thread */
    void endProcessing(int);

public slots:
    void setNutronData(NeutronData *neutron_data);


};

#endif // AVERAGETHREAD_H
