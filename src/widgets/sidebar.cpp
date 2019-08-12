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

    SideBarUnit *unit1 = new SideBarUnit("Open",":/icons/open_n.svg", ":/icons/open_a.svg");
    SideBarUnit *unit2 = new SideBarUnit("Test1",":/icons/test1.png", ":/icons/test1.png");
    SideBarUnit *unit3 = new SideBarUnit("Help",":/icons/help_n.svg", ":/icons/help_a.svg");

    addUnit(unit1);
    addUnit(unit2);
    addStretch(0);
    addUnit(unit3);



    this->setMaximumWidth(100);
    /* Palette */
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor("#434343"));
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

void SideBar::unitClicked(int index){
    for(int i=0;i<unit_list->size();i++){
        if(i!=index) unit_list->at(i)->setPalleteNormal();
    }
}
