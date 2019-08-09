#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent){
    layout = new QHBoxLayout();
    ch_bar = new ChoseBar();

    layout->addWidget(ch_bar);

    this->setLayout(layout);


}

CentralWidget::~CentralWidget(){

}

void CentralWidget::addTab(QString name, QWidget *widget){

}
