/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent)
{
    sb = new SideBar();
    layout = new QHBoxLayout();

    layout->setMargin(0);
    layout->setSpacing(0);

    this->setLayout(layout);
    layout->addWidget(sb);

    //layout->itemAt(0)->setAlignment(Qt::AlignLeft);
    //layout->setAlignment(Qt::AlignLeft);

    connect(sb,SIGNAL(clickedUnit(int)),
            this,SLOT(slot_activate(int)));
}


CentralWidget::~CentralWidget(){
    delete sb;
    delete layout;
}

void CentralWidget::addTab(SideBarUnit *unit, QWidget *widget){
    sb->addUnit(unit);
    widgets.append(widget);
    layout->addWidget(widget);
    widget->hide();
}

/* set Tab and unselect buttons */
void CentralWidget::slot_activate(int index){
    for(int i=0;i<widgets.size();i++) widgets.at(i)->hide();
    widgets.at(index)->show();
    sb->unselectUnit(index);            // unselected all units (buttons on left tab) except index. Selection button inside SideBarUnit
    emit selected(index);
}

/* activate tab and select unit (not slot) */
void CentralWidget::activate(int index){
    slot_activate(index);
    sb->selectUnit(index);

}


void CentralWidget::addSplit(){
    sb->addStretch(0);
    /* my be need add painter line */
}
