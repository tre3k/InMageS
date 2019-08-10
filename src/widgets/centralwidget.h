#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

#include "sidebar.h"

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = nullptr);
    ~CentralWidget();

private:
    SideBar *sb;
    QHBoxLayout *layout;

signals:

public slots:
};

#endif // CENTRALWIDGET_H
