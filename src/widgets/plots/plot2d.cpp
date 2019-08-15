/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#include "plot2d.h"

Plot2D::Plot2D(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt, parent)
{
    /* place widgets on layouts */
    plot = new Plot();

    central_layout = new QVBoxLayout();
    central_layout->setMargin(0);
    tool_layout = new QHBoxLayout();

    combo_select_units = new QComboBox();
    spinBoxMax = new QDoubleSpinBox();
    spinBoxMin = new QDoubleSpinBox();
    check_hold = new QCheckBox("hold");
    check_log_scale = new QCheckBox("log");

    spinBoxMax->setRange(-999999999.999,999999999.999);
    spinBoxMin->setRange(-999999999.999,999999999.999);
    spinBoxMax->setDecimals(3);
    spinBoxMin->setDecimals(3);

    spinBoxMax->setValue(100.0);
    spinBoxMin->setValue(-100.0);

    spinBoxMax->setMaximumWidth(80);
    spinBoxMin->setMaximumWidth(80);

    combo_select_units->addItem("pixels");
    combo_select_units->addItem("wave vector [1/A]");
    combo_select_units->addItem("wave vector [1/nm]");
    combo_select_units->addItem("angle θ [mrad]");

    tool_layout->setMargin(0);
    tool_layout->addWidget(new QLabel("Unit:"));
    tool_layout->addWidget(combo_select_units);
    tool_layout->addStretch();
    tool_layout->addWidget(new QLabel("max:"));
    tool_layout->addWidget(spinBoxMax,0,Qt::AlignRight);
    tool_layout->addWidget(new QLabel("min:"));
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
    connect(check_hold,SIGNAL(clicked(bool)),
            this,SLOT(hold(bool)));


}


void Plot2D::buildNeutronData(NeutronData *n_data){
    setNeutronData(n_data);
    buildNeutronData();
    return;
}

void Plot2D::setNeutronData(NeutronData *n_data){
    neutron_data = n_data;
}

void Plot2D::buildNeutronData(){
    if(neutron_data==nullptr) return;
    colorMap->data()->setSize(int(neutron_data->size_Nx()),int(neutron_data->size_Ny()));
    for(int i=0;i<int(neutron_data->size_Nx());i++){
        for(int j=0;j<int(neutron_data->size_Ny());j++){
            colorMap->data()->setCell(i,j,neutron_data->data_matrix->at((unsigned long int) i, (unsigned long int) j));
        }
    }
    return;
}

void Plot2D::logScale(bool state){
    if(state){
        colorMap->setDataScaleType(QCPAxis::stLogarithmic);
    }else{
        colorMap->setDataScaleType(QCPAxis::stLinear);
    }
    setHoldRange();
    return;
}

void Plot2D::hold(bool state){
    if(state){
        connect(spinBoxMax,SIGNAL(valueChanged(double)),
                this,SLOT(setHoldRange()));
        connect(spinBoxMin,SIGNAL(valueChanged(double)),
                this,SLOT(setHoldRange()));
    }else{
        disconnect(spinBoxMax,SIGNAL(valueChanged(double)),
                this,SLOT(setHoldRange()));
        disconnect(spinBoxMin,SIGNAL(valueChanged(double)),
                this,SLOT(setHoldRange()));
    }
    setHoldRange();
}

void Plot2D::setHoldRange(){
    if(check_hold->isChecked()) colorMap->setDataRange(QCPRange(spinBoxMin->value(),spinBoxMax->value()));
    plot->rescaleAxes(!check_hold->isChecked());
    plot->replot();
}
