#include "tabhelp.h"

TabHelp::TabHelp(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt,parent)
{
    layout = new QVBoxLayout();
    helpButton = new QPushButton("Help ?");
    helpButton->setMaximumWidth(50);
    QLabel *label_top = new QLabel("<b>InMageS</b> - INelastic MAGnEt Scattering<br>");
    label_top->setAlignment(Qt::AlignHCenter);

    QLabel *label_copyright = new QLabel(
                "Copyright (c) 2019<br>"
                "Petersburg Nuclear Physics Institute named by B.P.Konstantinov of NRC «Kurchatov Institute» PNPI<br>"
                "Saint-Petersburg State University<br>"
                "Autor: Kirill Pshenichnyi (pshcyrill@mail.ru)<br>");
    QLabel *label_license =new QLabel("GNU GPLv3, Source code: <a href=\"https://github.com/tre3k/InMageS\">GitHub: https://github.com/tre3k/InMageS</a>");
    label_copyright->setTextInteractionFlags(Qt::TextSelectableByMouse);
    label_copyright->setAlignment(Qt::AlignLeft);
    layout->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    layout->addWidget(label_top);
    layout->addWidget(label_copyright);
    layout->addWidget(label_license);
    layout->addWidget(helpButton);
    //layout->addWidget(new QPushButton("sdasd"));

    this->setLayout(layout);

    connect(helpButton,SIGNAL(clicked()),
            this,SLOT(helpButtonClick()));
}


void TabHelp::helpButtonClick(){

}
