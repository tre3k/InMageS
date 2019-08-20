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


    layout_top = new QVBoxLayout();
    this->setLayout(layout_top);
    layout_top->addLayout(layout_combo);


    a_threads.clear();
}

AverageWidget::~AverageWidget(){

}


void AverageWidget::addAverageThread(AverageThread *average_thread){
    combo_select->addItem(average_thread->getName());
    a_threads.append(average_thread);
    return;
}
