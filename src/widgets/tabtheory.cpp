/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#include "tabtheory.h"

TabTheory::TabTheory(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt, parent)
{
    // top level layout
    top_layout = new QGridLayout();
    this->setLayout(top_layout);

    plot_map = new Plot2D();
    plot_average = new Plot();


    QSplitter *splitter = new QSplitter();
    splitter->setAttribute(Qt::WA_DeleteOnClose);
    splitter->setOrientation(Qt::Horizontal);

    splitter->addWidget(plot_map);
    splitter->addWidget(plot_average);

    // need use other layout?
    top_layout->addWidget(splitter,0,0);
    //top_layout->addWidget(plot_average,0,1);
    //top_layout->addWidget(plot_map,0,0);
}

