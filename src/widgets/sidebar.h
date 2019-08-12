#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QVector>
#include <QVBoxLayout>

#include "sidebarunit.h"

class SideBar : public QWidget
{
    Q_OBJECT
public:
    explicit SideBar(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QVector<SideBarUnit *> *unit_list;

signals:

public slots:
    void addUnit(SideBarUnit *unit);
    void addStretch(int size);
    void unitClicked(int index);

};

#endif // SIDEBAR_H
