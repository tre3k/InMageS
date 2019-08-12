#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>
#include <QDebug>
#include <QProgressBar>

#include "sidebarunit.h"  // Just for BACKGROUND_COLOR

class StatusBar : public QStatusBar
{
    Q_OBJECT
public:
    StatusBar(QWidget *parent = nullptr);
    ~StatusBar();

    int getProgressBar(void);

private:
    QProgressBar *progressBar;

public slots:
    void showProgressBar();
    void hideProgressBar();
    void setProgressBar(int value);

};



#endif // STATUSBAR_H
