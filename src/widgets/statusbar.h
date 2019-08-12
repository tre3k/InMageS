#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>
#include <QDebug>

#include "sidebarunit.h"  // Just for BACKGROUND_COLOR

class StatusBar : public QStatusBar
{
    Q_OBJECT
public:
    StatusBar(QWidget *parent = nullptr);
    ~StatusBar();
};



#endif // STATUSBAR_H
