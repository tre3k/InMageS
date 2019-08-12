#include "tabhelp.h"

TabHelp::TabHelp(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout();
    QLabel *label = new QLabel("Copyright (c) PNPI 2019\n"
                 "Kirill Pshenichnyi (pshcyrill@mail.ru)");
    label->setAlignment(Qt::AlignHCenter);

    layout->addWidget(label);
    layout->addWidget(new QPushButton("sdasd"));

    this->setLayout(layout);
}
