/* mainwindow.h
 * Copyright 2019 Sep
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#ifndef OPENDBWIDGET_H
#define OPENDBWIDGET_H

#include "basewidget.h"

class OpenDBWidget : public BaseWidget
{
    Q_OBJECT
public:
    explicit OpenDBWidget(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // OPENDBWIDGET_H
