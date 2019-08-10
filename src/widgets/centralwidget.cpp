#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
    sb = new SideBar();
    layout = new QHBoxLayout();
    this->setLayout(layout);
    layout->addWidget(sb);

    layout->setMargin(0);
}


CentralWidget::~CentralWidget(){
    delete sb;
    delete layout;
}
