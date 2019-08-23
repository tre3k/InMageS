/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

// Thread for show message and set progress bar on statusbar
// also signals/slot for send/recv the links for other classes

#ifndef STATUSBARTHREAD_H
#define STATUSBARTHREAD_H

#include <QThread>
#include <QDebug>
#include <QMutex>

#include "widgets/statusbar.h"

class StatusBarThread : public QThread
{
    Q_OBJECT
public:
    explicit StatusBarThread(QObject *parent = nullptr);

private:
    void run() override;
    StatusBar *link_to_statusbar;

protected:
    QMutex *mutex;

signals:

public slots:
    void recvLinkToStatusBar(StatusBar *lnk);
    void setProgressBar(int value);
    void showMessage(QString message);

};

#endif // STATUSBARTHREAD_H
