/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#ifndef TABSAVE_H
#define TABSAVE_H

#include "basewidget.h"

class TabSave : public BaseWidget
{
    Q_OBJECT
public:
    explicit TabSave(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TABSAVE_H
