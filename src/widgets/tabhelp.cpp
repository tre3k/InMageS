#include "tabhelp.h"

TabHelp::TabHelp(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt,parent)
{
    layout = new QVBoxLayout();
    QLabel *label = new QLabel(
                "<b>InMageS</b> - Inelastic Magnet Scattering<br>"
                "Copyright (c) PNPI 2019 "
                "Kirill Pshenichnyi (pshcyrill@mail.ru)");
    label->setAlignment(Qt::AlignHCenter);
    layout->setAlignment(Qt::AlignVCenter);

    layout->addWidget(label);
    //layout->addWidget(new QPushButton("sdasd"));

    this->setLayout(layout);
}
