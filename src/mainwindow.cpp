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


    return;
}

MainWindow::~MainWindow(){
    delete cw;
}
