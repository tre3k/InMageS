/* mainwindow.cpp
 * Copyright 2019 7 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    cw = new CentralWidget();
    sb = new StatusBar();

    this->setCentralWidget(cw);
    this->setStatusBar(sb);

    this->setWindowTitle("InMageS - Inelastic Magnet Scattering");
    this->setMinimumWidth(MAINWINDOW_MINIMUM_W);
    this->setMinimumHeight(MAINWINDOW_MINIMUM_H);



    SideBarUnit *open_unit = new SideBarUnit("Open",":/icons/open_n.svg", ":/icons/open_a.svg");
    SideBarUnit *processing_unit = new SideBarUnit("Processing",":/icons/processing_n.svg", ":/icons/processing_a.svg");
    SideBarUnit *theory_unit = new SideBarUnit("Theory",":/icons/theory_n.svg", ":/icons/theory_a.svg");
    SideBarUnit *help_unit = new SideBarUnit("Help",":/icons/help_n.svg", ":/icons/help_a.svg");

    cw->addTab(open_unit,new QLabel("test1"));
    cw->addTab(processing_unit,new QLabel("test2"));
    cw->addTab(theory_unit,new QLabel("test3"));
    cw->addSplit();
    cw->addTab(help_unit,new QLabel("test4"));

    cw->activate(0);


    sb->showMessage("Ready");
    return;
}

MainWindow::~MainWindow(){
    delete cw;
}
