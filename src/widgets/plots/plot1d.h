/* mainwindow.h
 * Copyright 2019 13 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#ifndef PLOT1D_H
#define PLOT1D_H

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include "widgets/basewidget.h"
#include "widgets/plots/plot.h"

class Plot1D : public BaseWidget
{
public:
    Plot1D(StatusBarThread *sbt=nullptr, QWidget *parent = nullptr);
    ~Plot1D();

private:
    QVBoxLayout *layout;
    QHBoxLayout *tool_layout;

    Plot *plot;
    QPushButton *button_clean;
    QPushButton *button_rescale;

public slots:
    void clean(){plot->clearGraphs();}
    void rescaleAxis();

};

#endif // PLOT1D_H
