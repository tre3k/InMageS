#ifndef TABSAVE_H
#define TABSAVE_H

#include "basewidget.h"

class TabSave : public BaseWidget
{
    Q_OBJECT
public:
    explicit TabSave(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TABSAVE_H
