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

    SideBarUnit *unit1 = new SideBarUnit("Test2",":/icons/test2.png");
    SideBarUnit *unit2 = new SideBarUnit("Test1",":/icons/test1.png");

    addUnit(unit1);
    addUnit(unit2);
    layout->addStretch(0);


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
    return;
}
