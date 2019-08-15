/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#include "plot2d.h"

Plot2D::Plot2D(QWidget *parent) : QWidget(parent)
{
    /* place widgets on layouts */
    plot = new Plot();

    central_layout = new QVBoxLayout();
    tool_layout = new QHBoxLayout();

    combo_select_units = new QComboBox();
    spinBoxMax = new QDoubleSpinBox();
    spinBoxMin = new QDoubleSpinBox();
    check_hold = new QCheckBox("hold");
    check_log_scale = new QCheckBox("log");


    tool_layout->setSpacing(1);
    tool_layout->addWidget(combo_select_units);
    tool_layout->addStretch();
    tool_layout->addWidget(spinBoxMax,0,Qt::AlignRight);
    tool_layout->addWidget(spinBoxMin,0,Qt::AlignRight);
    tool_layout->addWidget(check_hold,0,Qt::AlignRight);
    tool_layout->addWidget(check_log_scale,0,Qt::AlignRight);

    central_layout->addWidget(plot);
    central_layout->addLayout(tool_layout);

    this->setLayout(central_layout);

    /* set 2d plot (colorMap colorScale, etc*/
    colorMap = new QCPColorMap(plot->xAxis,plot->yAxis);
    colorScale = new QCPColorScale(plot);
    colorScale->setType(QCPAxis::atRight);
    plot->plotLayout()->addElement(0,1,colorScale);

    colorMap->setColorScale(colorScale);
    colorMap->setGradient(QCPColorGradient::gpJet);


    connect(check_log_scale,SIGNAL(clicked(bool)),
            this,SLOT(logScale(bool)));

}


void Plot2D::buildNeutronData(NeutronData *n_data){

}


void Plot2D::logScale(bool state){
    if(state){
        colorMap->setDataScaleType(QCPAxis::stLogarithmic);
    }else{
        colorMap->setDataScaleType(QCPAxis::stLinear);
    }
    plot->replot();
    return;
}
