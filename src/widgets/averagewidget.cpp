#include "averagewidget.h"

AverageWidget::AverageWidget(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt, parent)
{
    button_add = new QPushButton("+");
    button_rm = new QPushButton("-");
    button_average = new QPushButton("average");
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
    spinBox_lenght = new QDoubleSpinBox();
    spinBox_open_angle = new QDoubleSpinBox();
    spinBox_open_angle->setSuffix(" degree");
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
    layout_elements->addRow("",button_average);

    layout_top = new QVBoxLayout();
    this->setLayout(layout_top);
    layout_top->addLayout(layout_combo);
    layout_top->addLayout(layout_elements);


    a_threads.clear();
}

AverageWidget::~AverageWidget(){

}


void AverageWidget::addAverageThread(AverageThread *average_thread){
    combo_select->addItem(average_thread->getName());
    a_threads.append(average_thread);

    //spinBox_angle->setValue();

    return;
}
