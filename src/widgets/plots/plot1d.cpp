/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#include "plot1d.h"

Plot1D::Plot1D(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt,parent)
{
    layout = new QVBoxLayout();
    layout->setMargin(0);
    this->setLayout(layout);

    /* init base plot class */
    plot = new Plot();

    /* bottom layout */
    tool_layout = new QHBoxLayout();
    button_clean = new QPushButton("clean");
    button_rescale = new QPushButton("rescale");
    tool_layout->addWidget(button_clean);
    tool_layout->addWidget(button_rescale);
    tool_layout->addStretch(0);

    /* top level layout */
    layout->addWidget(plot);
    layout->addLayout(tool_layout);
}

Plot1D::~Plot1D(){
    delete plot;
    delete button_clean;
    delete button_rescale;
}

void Plot1D::rescaleAxis(){

}
