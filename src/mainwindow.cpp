/* mainwindow.cpp
 * Copyright 2019 7 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    cw = new CentralWidget();

    this->setCentralWidget(cw);

    QWidget *testWidget = new QWidget();
    QVBoxLayout *testLayout = new QVBoxLayout();
    testWidget->setLayout(testLayout);
    testLayout->addWidget(new QLabel("test"));
    cw->addTab("Test",testWidget);

    QWidget *testWidget2 = new QWidget();
    QVBoxLayout *testLayout2 = new QVBoxLayout();
    testWidget2->setLayout(testLayout2);
    testLayout2->addWidget(new QLabel("test2"));
    cw->addTab("Test2",testWidget2);
}

MainWindow::~MainWindow(){
  
}
