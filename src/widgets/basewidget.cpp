/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#include "basewidget.h"

BaseWidget::BaseWidget(StatusBarThread *sbt, QWidget *parent) : QWidget(parent)
{
    connect(this,SIGNAL(setProgressBar(int)),
            sbt,SLOT(setProgressBar(int)));
    connect(this,SIGNAL(showMessage(QString)),
            sbt,SLOT(showMessage(QString)));
}
