/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#ifndef TABOPEN_H
#define TABOPEN_H

#include <QTabWidget>
#include <QVBoxLayout>

#include "basewidget.h"
#include "openrawfilewidget.h"
#include "opendbwidget.h"

class TabOpen : public BaseWidget
{
    Q_OBJECT
public:
    explicit TabOpen(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TABOPEN_H
