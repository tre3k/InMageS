#include "chosebar.h"

ChoseBar::ChoseBar(QWidget *parent) : QListWidget(parent)
{
    this->addItem("Processing");
    this->addItem("Theory");



    return;
}

ChoseBar::~ChoseBar(){
    return;
}
