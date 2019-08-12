/* mainwindow.h
 * Copyright 2019 7 Aug 
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering) 
 * Software for Build analitical data and processing experemental data
 */ 


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QLabel>
#include <QMenuBar>
#include <QApplication>

#include "widgets/centralwidget.h"
#include "widgets/statusbar.h"

/* include tabs on mainWidget*/
#include "widgets/tabopen.h"
#include "widgets/tabtheory.h"
#include "widgets/tabprocessing.h"
#include "widgets/tabsave.h"
#include "widgets/tabhelp.h"


#define MAINWINDOW_MINIMUM_W 600
#define MAINWINDOW_MINIMUM_H 400

enum{
    TAB_OPEN,
    TAB_THEORY,
    TAB_PROCESSING,
    TAB_SAVE,
    TAB_HELP,
    TAB_EXIT
};

class MainWindow : public QMainWindow{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private:

    CentralWidget *cw;
    StatusBar *sb;

  private slots:
    void mainWidgetActivate(int index);

};


#endif // MAIN_WINDOW_H
