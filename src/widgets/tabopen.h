#ifndef TABOPEN_H
#define TABOPEN_H

#include "basewidget.h"

class TabOpen : public BaseWidget
{
    Q_OBJECT
public:
    explicit TabOpen(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TABOPEN_H
