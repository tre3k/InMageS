#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>
#include <QDebug>


class StatusBar : public QStatusBar
{
    Q_OBJECT
public:
    StatusBar(QWidget *parent = nullptr);
    ~StatusBar();
};



#endif // STATUSBAR_H
