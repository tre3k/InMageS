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

    /* Place main widgets to MainWindow */
    this->setCentralWidget(cw);
    this->setStatusBar(sb);

    /* Run statusbar thread*/
    sbt = new StatusBarThread();
    sbt->start();
    connect(this,SIGNAL(sendStatusBarLink(StatusBar *)),
            sbt,SLOT(recvLinkToStatusBar(StatusBar *)));
    emit sendStatusBarLink(sb);

    /* set tabs to central widget */
    auto *open_unit = new SideBarUnit("Open",":/icons/open_n.svg", ":/icons/open_a.svg");
    auto *processing_unit = new SideBarUnit("Processing",":/icons/processing_n.svg", ":/icons/processing_a.svg");
    auto *theory_unit = new SideBarUnit("Theory",":/icons/theory_n.svg", ":/icons/theory_a.svg");
    auto *help_unit = new SideBarUnit("About",":/icons/help_n.svg", ":/icons/help_a.svg");
    auto *save_unit = new SideBarUnit("Save", ":/icons/save_n.svg", ":/icons/save_a.svg");
    auto *exit_unit = new SideBarUnit("Exit", ":/icons/exit_n.svg", ":/icons/exit_a.svg");

    auto *open_widget = new TabOpen(sbt);
    auto *theory_widget = new TabTheory(sbt);
    auto *processing_widget = new TabProcessing(sbt);
    auto *save_widget = new TabSave(sbt);
    auto *help_widget = new TabHelp(sbt);

    cw->addTab(open_unit, open_widget);
    cw->addTab(theory_unit, theory_widget);
    cw->addTab(processing_unit, processing_widget);
    cw->addTab(save_unit,save_widget);
    cw->addSplit();
    cw->addTab(help_unit, help_widget);
    cw->addTab(exit_unit,new QLabel("<center><b>Good bay!</b></center>"));

    cw->activate(0);

    /* MainWindow propery */
    this->setWindowTitle("InMageS - Inelastic Magnet Scattering");
    this->setMinimumWidth(MAINWINDOW_MINIMUM_W);
    this->setMinimumHeight(MAINWINDOW_MINIMUM_H);

    //Default
    QDesktopWidget dw;
    /* just 70% of Display */
    this->setGeometry(int(dw.width()/2-dw.width()*0.7/2),
                      int(dw.height()/2-dw.height()*0.7/2),
                      int(dw.width()*0.7),int(dw.height()*0.7));

    connect(cw,SIGNAL(selected(int)),
            this,SLOT(mainWidgetActivate(int)));

    /* MenuBar */
    menuBar = new QMenuBar();
    QMenu *menuFile = new QMenu("&File");
    QAction *actionExit = new QAction("E&xit");
    actionExit->setIcon(QIcon(":/icons/exit_a.svg"));
    menuFile->addAction(actionExit);

    menuBar->addMenu(menuFile);
    this->setMenuBar(menuBar);

    connect(actionExit,SIGNAL(triggered()),
            this,SLOT(quit()));

    sb->showMessage("Ready");


    NeutronData *nd = new NeutronData(128,128);
    nd->lambda = 5;
    nd->update_ki_Ei();

    qDebug() << nd->get_ki();

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
        quit();
        break;
    }
}

void MainWindow::quit(){
    auto reply = QMessageBox::question(nullptr,"Are you seriously?","You want to quit?",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
        QApplication::quit();
    }
}
