/* main.cpp
 * Copyright 2019 7 Aug 
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering) 
 * Software for Build analitical data and processing experemental data
 */ 


#include <QApplication>

#include "mainwindow.h"

int main(int argc,char **argv){
    QApplication a(argc,argv);

    MainWindow *mainwindow = new MainWindow();
    mainwindow->show();
    
    return a.exec();
}
