#ifndef TABPROCESSING_H
#define TABPROCESSING_H

#include "basewidget.h"

class TabProcessing : public BaseWidget
{
    Q_OBJECT
public:
    explicit TabProcessing(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TABPROCESSING_H
