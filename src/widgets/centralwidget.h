#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVector>

#include "sidebar.h"
#include "sidebarunit.h"

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = nullptr);
    ~CentralWidget();
    void activate(int index);

private:
    SideBar *sb;
    QHBoxLayout *layout;
    QVector<QWidget *> widgets;

signals:
    void selected(int);

public slots:
    void addTab(SideBarUnit *sbUnit, QWidget *widget);
    void slot_activate(int index);
    void addSplit();
};

#endif // CENTRALWIDGET_H
