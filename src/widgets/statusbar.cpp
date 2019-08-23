/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#include "statusbar.h"

StatusBar::StatusBar(QWidget *parent) : QStatusBar(parent)
{
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(BACKGROUND_COLOR));
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    progressBar = new QProgressBar();
    progressBar->setMaximumWidth(100);
    progressBar->setMaximumHeight(14);

    this->addPermanentWidget(progressBar);

    progressBar->hide();
}

StatusBar::~StatusBar(){

}

int StatusBar::getProgressBar(){
    return progressBar->value();
}

void StatusBar::showProgressBar(){
    progressBar->show();
}

void StatusBar::hideProgressBar(){
    progressBar->hide();
}

void StatusBar::setProgressBar(int value){
    progressBar->setValue(value);
}

