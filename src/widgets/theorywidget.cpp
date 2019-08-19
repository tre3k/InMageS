#include "theorywidget.h"

TheoryWidget::TheoryWidget(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt,parent)
{
    layout = new QHBoxLayout();

    this->setLayout(layout);

    /* left layout with field of values and button */
    layoutForm = new QFormLayout();

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
    spinBox_field->setSingleStep(0.1);
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

    layoutForm->addRow("Type:",comboSelectType);
    layoutForm->addRow("Stiffness: ",spinBox_stiffness);
    layoutForm->addRow("Magnet field: ",spinBox_field);
    layoutForm->addRow("k\u209b: ",spinBox_ks);
    layoutForm->addRow("Wave lenght: ",spinBox_lambda);
    layoutForm->addRow("Distance detector to source: ",spinBox_Dsd);
    layoutForm->addRow("detector of resolution: ",layout_NxNy);
    layoutForm->addRow("Pixel of size: ",layout_pxpy);
    layoutForm->addRow("",button_build);


    /* output calculate value */
    label_Ei_K = new QLabel();
    label_Ei_meV = new QLabel();
    label_theta_0 = new QLabel();
    label_theta_C = new QLabel();
    label_theta_B = new QLabel();

    auto gBox = new QGroupBox("calculate values: ");
    auto layout_box = new QFormLayout();

    gBox->setLayout(layout_box);
    layout_box->addRow("θ<sub>0</sub>: ",label_theta_0);
    layout_box->addRow("θ<sub>C</sub>: ",label_theta_C);
    layout_box->addRow("θ<sub>B</sub>: ",label_theta_B);
    layout_box->addRow("E<sub>i</sub>: ", label_Ei_meV);
    layout_box->addRow("",label_Ei_K);


    layout->addLayout(layoutForm);
    //layout->addStretch(0);
    layout->addWidget(gBox);


    connect(spinBox_lambda,SIGNAL(valueChanged(double)),
            this,SLOT(updateLabelEnergy()));
}


void TheoryWidget::build(){
    if((nd->size_Nx() != (unsigned long int)(spinBox_Nx->value())) ||
       (nd->size_Ny() != (unsigned long int)(spinBox_Ny->value()))){
            nd->resize((unsigned long int)spinBox_Nx->value(),
                       (unsigned long int)spinBox_Ny->value());
    }

    Theory theory(nd);
    nd->setDlpxpy(spinBox_Dsd->value(),
                  spinBox_lambda->value(),
                  spinBox_px->value(),
                  spinBox_py->value());

    switch (comboSelectType->currentIndex()) {
    case TheoryType::THEORY_TYPE_FERROMAGNET:
        //theory.calculateFerromagnet(spinBox_field->value(),spinBox_stiffness->value());
        theory.calculateFerromagnet(0.5,100);
        break;

    case TheoryType::THEORY_TYPE_HELICOMAGNET:
        theory.calculateHelimagnet(spinBox_field->value(),spinBox_ks->value(),spinBox_stiffness->value());
        label_theta_B->setText(QString::number(1000*theory.getThetaB())+ " mrad");
        break;
    }
    p2d->buildNeutronData(nd);

    label_theta_0->setText(QString::number(1000*theory.getTheta0()) + " mrad");
    label_theta_C->setText(QString::number(1000*sqrt(theory.getThetaC2())) + " mrad");
}

void TheoryWidget::updateLabelEnergy(){
    nd->setWaveLenght(spinBox_lambda->value());
    label_Ei_meV->setText(QString::number(nd->getEi_meV()) + "meV");
    label_Ei_K->setText(QString::number(nd->getEi_K()) + " K");
}
