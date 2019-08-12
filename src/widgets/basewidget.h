#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <QString>

#include "threads/statusbarthread.h"

class BaseWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseWidget(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);

signals:
    void setProgressBar(int value);
    void showMessage(QString);

public slots:
};

#endif // BASEWIDGET_H
