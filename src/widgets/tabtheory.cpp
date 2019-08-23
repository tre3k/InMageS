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
    plot_average = new Plot1D(sbt);

    tw = new TheoryWidget(sbt);
    aw = new AverageWidget(sbt);


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
    splitter_upper->setSizes(QList<int>() << 20 << splitter_upper->size().width()-20 );

    /* add bottom widgets to splitter */
    splitter_lower->addWidget(tw);
    splitter_lower->addWidget(aw);


    splitter_top->addWidget(splitter_upper);
    splitter_top->addWidget(splitter_lower);
    splitter_top->setSizes(QList<int>() << splitter_top->size().height()-20 << 20);

    top_layout->addWidget(splitter_top,0,0);

    /* test plot2D and theory */
    NeutronData *nd = new NeutronData(1023,1023);
    tw->setNdPl(nd,plot_map);

    /* test average widget */
    AverageThread *awth = new AverageThread();
    awth->setName("Left");
    awth->setNutronData(nd);
    // Add item
    aw->addAverageThread(awth);
}

