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

    this->setMaximumWidth(100);
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
