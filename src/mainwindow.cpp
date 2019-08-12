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
    SideBarUnit *save_unit = new SideBarUnit("Save", ":/icons/save_n.svg", ":/icons/save_a.svg");
    SideBarUnit *exit_unit = new SideBarUnit("Exit", ":/icons/exit_a.svg", ":/icons/exit_a.svg");

    TabOpen *open_widget = new TabOpen();
    TabTheory *theory_widget = new TabTheory();
    TabProcessing *processing_widget = new TabProcessing();
    TabSave *save_widget = new TabSave();
    TabHelp *help_widget = new TabHelp();

    cw->addTab(open_unit, open_widget);
    cw->addTab(theory_unit, theory_widget);
    cw->addTab(processing_unit, processing_widget);
    cw->addTab(save_unit,save_widget);
    cw->addSplit();
    cw->addTab(help_unit, help_widget);
    cw->addTab(exit_unit,new QLabel("Good bay!"));

    cw->activate(0);

    sb->showMessage("Ready");

    connect(cw,SIGNAL(selected(int)),
            this,SLOT(mainWidgetActivate(int)));
    return;
}

MainWindow::~MainWindow(){
    delete cw;
}

void MainWindow::mainWidgetActivate(int index){
    switch(index){
    case TAB_OPEN:
        break;

    case TAB_EXIT:
        QApplication::quit();
        break;
    }
}
