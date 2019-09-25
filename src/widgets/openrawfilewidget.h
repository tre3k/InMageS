/* mainwindow.h
 * Copyright 2019 Sep
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#ifndef OPENRAWFILEWIDGET_H
#define OPENRAWFILEWIDGET_H

#include "basewidget.h"

class OpenRawFileWidget : public BaseWidget
{
    Q_OBJECT
public:
    explicit OpenRawFileWidget(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // OPENRAWFILEWIDGET_H
