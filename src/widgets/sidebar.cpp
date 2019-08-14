/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#include "sidebar.h"

SideBar::SideBar(QWidget *parent) : QWidget(parent)
{
    /* list for units */
    unit_list = new QVector<SideBarUnit *>;

    /* set layout */
    layout = new QVBoxLayout();
    this->setLayout(layout);
    layout->setSpacing(0);
    layout->setMargin(0);

    this->setMaximumWidth(MAX_WIDTH);
    /* Palette */
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(BACKGROUND_COLOR));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}


void SideBar::addUnit(SideBarUnit *unit){
    unit_list->append(unit);
    layout->addWidget(unit);
    unit->setIndex(unit_list->size()-1);

    connect(unit,SIGNAL(clicked(int)),
            this,SLOT(unitClicked(int)));
    return;
}

void SideBar::addStretch(int size){
    layout->addStretch(size);
    QPixmap spliter(":/icons/split.svg");
    QLabel *label = new QLabel();
    label->setAlignment(Qt::AlignHCenter);
    label->setPixmap(spliter.scaled(70,50,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    layout->addWidget(label);
}

void SideBar::unselectUnit(int index){
    for(int i=0;i<unit_list->size();i++){
        if(i!=index) unit_list->at(i)->setPalleteNormal();
    }
}

void SideBar::selectUnit(int index){
    unit_list->at(index)->setPalleteSelectedWithoutAnimation();
}

void SideBar::unitClicked(int index){
    unselectUnit(index);
    emit clickedUnit(index);
}
