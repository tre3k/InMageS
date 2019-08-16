/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#include "tabtheory.h"

TabTheory::TabTheory(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt, parent)
{
    // top level layout
    top_layout = new QGridLayout();
    this->setLayout(top_layout);

    plot_map = new Plot2D(sbt);
    plot_average = new Plot();


    QSplitter *splitter_top = new QSplitter();
    splitter_top->setAttribute(Qt::WA_DeleteOnClose);
    splitter_top->setOrientation(Qt::Vertical);
    QSplitter *splitter = new QSplitter();
    splitter->setAttribute(Qt::WA_DeleteOnClose);
    splitter->setOrientation(Qt::Horizontal);

    splitter->addWidget(plot_map);
    splitter->addWidget(plot_average);

    // need relitive value
    splitter->setSizes(QList<int>() << 100 << 600);

    splitter_top->addWidget(splitter);
    splitter_top->addWidget(new QPushButton("asdsad"));

    // need use other layout?
    top_layout->addWidget(splitter_top,0,0);
    //top_layout->addWidget(plot_average,0,1);
    //top_layout->addWidget(plot_map,0,0);



    /* test plot2D and theory */
    NeutronData *nd = new NeutronData(1023,1023);
    nd->setDlpxpy(180,5.1,8,8);

    Theory *ther = new Theory(nd);
    ther->calculateFerromagnet(.1,100);
    qDebug() << "theta_0: " << ther->getTheta0();
    qDebug() << "theta_C2: " << sqrt(ther->getThetaC2());
    plot_map->buildNeutronData(nd);
}

