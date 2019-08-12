#include "statusbarthread.h"

StatusBarThread::StatusBarThread(QObject *parent) : QThread(parent)
{

}

void StatusBarThread::run(){
    /* auto hide progress bar */
    while(1){
        QThread::msleep(8000);
        if(link_to_statusbar==NULL) continue;
        if((link_to_statusbar->getProgressBar()==0) ||
           (link_to_statusbar->getProgressBar()==100)) link_to_statusbar->hideProgressBar();

    }
}

void StatusBarThread::recvLinkToStatusBar(StatusBar *lnk){
    link_to_statusbar = lnk;
}

void StatusBarThread::setProgressBar(int value){
    link_to_statusbar->showProgressBar();
    link_to_statusbar->setProgressBar(value);
}

void StatusBarThread::showMessage(QString message){
    link_to_statusbar->showMessage(message);
}
