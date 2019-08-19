﻿/* mainwindow.h
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

    tw = new TheoryWidget(sbt);


    QSplitter *splitter_top = new QSplitter();
    splitter_top->setAttribute(Qt::WA_DeleteOnClose);
    splitter_top->setOrientation(Qt::Vertical);
    QSplitter *splitter_upper = new QSplitter();
    splitter_upper->setAttribute(Qt::WA_DeleteOnClose);
    splitter_upper->setOrientation(Qt::Horizontal);
    QSplitter *splitter_lower = new QSplitter();
    splitter_lower->setAttribute(Qt::WA_DeleteOnClose);
    splitter_lower->setOrientation(Qt::Horizontal);

    splitter_upper->addWidget(plot_map);
    splitter_upper->addWidget(plot_average);
    // need relitive value
    splitter_upper->setSizes(QList<int>() << 100 << 600);

    splitter_lower->addWidget(tw);
    splitter_lower->addWidget(new QLabel("empty field"));


    splitter_top->addWidget(splitter_upper);
    splitter_top->addWidget(splitter_lower);

    top_layout->addWidget(splitter_top,0,0);


    /* test plot2D and theory */
    NeutronData *nd = new NeutronData(1024,1024);
    nd->setDlpxpy(70,5.1,8,8);
    tw->setNdPl(nd,plot_map);

    /*
    Theory *ther = new Theory(nd);
    //ther->calculateFerromagnet(.1,100);
    ther->calculateHelimagnet(0.1,0.2,100.0);
    qDebug() << "theta_0: " << ther->getTheta0();
    qDebug() << "theta_C2: " << sqrt(ther->getThetaC2());
    qDebug() << "theta_B: " << ther->getThetaB();
    plot_map->buildNeutronData(nd);
    */
}

