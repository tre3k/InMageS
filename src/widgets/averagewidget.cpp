/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#include "averagewidget.h"

AverageWidget::AverageWidget(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt, parent)
{
    button_add = new QPushButton("+");
    button_rm = new QPushButton("-");
    button_average = new QPushButton("average");
    button_set = new QPushButton("set");
    combo_select = new QComboBox(this);

    layout_combo = new QHBoxLayout();
    layout_combo->addWidget(combo_select);
    layout_combo->addWidget(button_add);
    layout_combo->addWidget(button_rm);

    button_rm->setMaximumWidth(30);
    button_add->setMaximumWidth(30);


    /*spinBoxs*/
    spinBox_angle = new QDoubleSpinBox();
    spinBox_angle->setSuffix(" degree");
    spinBox_angle->setRange(-360.0, 360.0);
    spinBox_lenght = new QDoubleSpinBox();
    spinBox_open_angle = new QDoubleSpinBox();
    spinBox_open_angle->setSuffix(" degree");
    spinBox_open_angle->setRange(-360.0, 360.0);
    spinBox_offset = new QDoubleSpinBox();

    spinBox_pos_x = new QDoubleSpinBox();
    spinBox_pos_y = new QDoubleSpinBox();

    auto *layout_elements = new QFormLayout();
    layout_elements->addRow("Angle: ",spinBox_angle);
    layout_elements->addRow("Open angle: ",spinBox_open_angle);
    layout_elements->addRow("Lenght: ",spinBox_lenght);
    layout_elements->addRow("Offset: ",spinBox_offset);
    auto *layout_position = new QHBoxLayout();
    layout_position->addWidget(spinBox_pos_x);
    layout_position->addWidget(spinBox_pos_y);
    layout_elements->addRow("Center position x,y: ",layout_position);
    auto *layout_buttons = new QHBoxLayout();
    layout_buttons->addWidget(button_set);
    layout_buttons->addWidget(button_average);
    layout_elements->addRow("",layout_buttons);

    layout_top = new QVBoxLayout();
    this->setLayout(layout_top);
    layout_top->addLayout(layout_combo);
    layout_top->addLayout(layout_elements);

    a_threads.clear();


    connect(combo_select,SIGNAL(activated(int)),
            this,SLOT(setUIFromAveraging(int)));
    connect(button_set,SIGNAL(clicked()),
            this,SLOT(pressButtonSet()));

}

AverageWidget::~AverageWidget(){

}


void AverageWidget::addAverageThread(AverageThread *average_thread){
    combo_select->addItem(average_thread->getName());
    a_threads.append(average_thread);

    setUIFromAveraging(a_threads.size()-1);

    return;
}

void AverageWidget::setUIFromAveraging(int index){
    /* may be need make convert units */
    spinBox_angle->setValue(a_threads.at(index)->av->getAngle());
    spinBox_open_angle->setValue(a_threads.at(index)->av->getOpenAngle());
    spinBox_lenght->setValue(a_threads.at(index)->av->getLength());
    spinBox_offset->setValue(a_threads.at(index)->av->getOffset());
    spinBox_pos_x->setValue(a_threads.at(index)->av->getX0());
    spinBox_pos_y->setValue(a_threads.at(index)->av->getY0());
}

void AverageWidget::setAveragingFromUI(){
    a_threads.at(combo_select->currentIndex())->av->setAngle(spinBox_angle->value());
    a_threads.at(combo_select->currentIndex())->av->setOpenAngle(spinBox_open_angle->value());
    a_threads.at(combo_select->currentIndex())->av->setLenght(spinBox_lenght->value());
    a_threads.at(combo_select->currentIndex())->av->setOffset(spinBox_offset->value());
    a_threads.at(combo_select->currentIndex())->av->setX0(spinBox_pos_x->value());
    a_threads.at(combo_select->currentIndex())->av->setY0(spinBox_pos_y->value());
}

void AverageWidget::pressButtonAverage(){
    return;
}
