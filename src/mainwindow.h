/* mainwindow.h
 * Copyright 2019 7 Aug 
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering) 
 * Software for Build analitical data and processing experemental data
 */ 


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow{
  Q_OBJECT
  
  public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private:

  private slots:
    
};


#endif // MAIN_WINDOW_H
