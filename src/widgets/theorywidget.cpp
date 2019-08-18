#include "theorywidget.h"

TheoryWidget::TheoryWidget(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt,parent)
{
    layout = new QFormLayout();
    this->setLayout(layout);

    comboSelectType = new QComboBox();
    comboSelectType->addItem("Ferromagnet");
    comboSelectType->addItem("Helimagnet");

    button_build = new QPushButton("build");
    connect(button_build,SIGNAL(clicked()),
            this,SLOT(build()));

    spinBox_stiffness = new QDoubleSpinBox(this);
    spinBox_stiffness->setRange(0.0, 99999.999);
    spinBox_stiffness->setValue(101.2);
    spinBox_stiffness->setDecimals(3);
    spinBox_stiffness->setSuffix(" meVÅ\u00b2");

    spinBox_field = new QDoubleSpinBox(this);
    spinBox_field->setRange(0,99.999);
    spinBox_field->setDecimals(3);
    spinBox_field->setValue(0.03);
    spinBox_field->setSuffix(" T");

    spinBox_ks = new QDoubleSpinBox(this);
    spinBox_ks->setRange(0,99.999);
    spinBox_ks->setDecimals(3);
    spinBox_ks->setValue(0.12);
    spinBox_ks->setSuffix(" nm\u207b\u00b9");

    spinBox_lambda = new QDoubleSpinBox(this);
    spinBox_lambda->setRange(0,99.999);
    spinBox_lambda->setValue(5.1);
    spinBox_lambda->setSuffix(" Å");

    spinBox_Dsd = new QDoubleSpinBox(this);
    spinBox_Dsd->setRange(0,9999.999);
    spinBox_Dsd->setValue(20.0);
    spinBox_Dsd->setDecimals(3);
    spinBox_Dsd->setSuffix(" m");


    spinBox_Nx = new QSpinBox(this);
    spinBox_Ny = new QSpinBox(this);
    auto *layout_NxNy = new QHBoxLayout();
    layout_NxNy->addWidget(spinBox_Nx);
    layout_NxNy->addWidget(spinBox_Ny);
    spinBox_Nx->setRange(0,99999); spinBox_Nx->setValue(1024);
    spinBox_Ny->setRange(0,99999); spinBox_Ny->setValue(1024);

    spinBox_px = new QDoubleSpinBox(this);
    spinBox_py = new QDoubleSpinBox(this);
    auto *layout_pxpy = new QHBoxLayout();
    layout_pxpy->addWidget(spinBox_px);
    layout_pxpy->addWidget(spinBox_py);
    spinBox_px->setRange(0,99.99); spinBox_px->setValue(2.0); spinBox_px->setSuffix(" mm");
    spinBox_py->setRange(0,99.99); spinBox_py->setValue(2.0); spinBox_py->setSuffix(" mm");

    layout->addRow("Type:",comboSelectType);
    layout->addRow("Stiffness: ",spinBox_stiffness);
    layout->addRow("Magnet field: ",spinBox_field);
    layout->addRow("k\u209b",spinBox_ks);
    layout->addRow("Wave lenght: ",spinBox_lambda);
    layout->addRow("Distance detector to source: ",spinBox_Dsd);
    layout->addRow("detector of resolution: ",layout_NxNy);
    layout->addRow("Pixel of size: ",layout_pxpy);
    layout->addRow("",button_build);

}


void TheoryWidget::build(){
    Theory theory(nd);
    nd->setDlpxpy(spinBox_Dsd->value(),
                  spinBox_lambda->value(),
                  spinBox_px->value(),
                  spinBox_py->value());

    switch (comboSelectType->currentIndex()) {
    case TheoryType::THEORY_TYPE_FERROMAGNET:
        theory.calculateFerromagnet(spinBox_field->value(),spinBox_stiffness->value());
        break;

    case TheoryType::THEORY_TYPE_HELICOMAGNET:
        theory.calculateHelimagnet(spinBox_field->value(),spinBox_ks->value(),spinBox_stiffness->value());
        break;
    }
    p2d->buildNeutronData(nd);

}
