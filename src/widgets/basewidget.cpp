#include "basewidget.h"

BaseWidget::BaseWidget(StatusBarThread *sbt, QWidget *parent) : QWidget(parent)
{
    connect(this,SIGNAL(setProgressBar(int)),
            sbt,SLOT(setProgressBar(int)));
    connect(this,SIGNAL(showMessage(QString)),
            sbt,SLOT(showMessage(QString)));
}
