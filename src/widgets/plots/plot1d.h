/* mainwindow.h
 * Copyright 2019 13 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#ifndef PLOT1D_H
#define PLOT1D_H

#include <QWidget>
#include "plot.h"

class Plot1D : public QWidget
{
public:
    Plot1D(QWidget *parent = nullptr);
};

#endif // PLOT1D_H
