/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <QWidget>
#include <QVector>
#include <QVBoxLayout>
#include <QPainter>

#include "sidebarunit.h"

#define MAX_WIDTH 100

class SideBar : public QWidget
{
    Q_OBJECT
public:
    explicit SideBar(QWidget *parent = nullptr);
    void unselectUnit(int index);
    void selectUnit(int index);

private:
    QVBoxLayout *layout;
    QVector<SideBarUnit *> *unit_list;

signals:
    void clickedUnit(int);

public slots:
    void addUnit(SideBarUnit *unit);
    void addStretch(int size);
    void unitClicked(int index);

};

#endif // SIDEBAR_H
