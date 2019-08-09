#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVector>

#include "chosebar.h"

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    CentralWidget(QWidget *parent = nullptr);
    ~CentralWidget();

public:
    void addTab(QString name, QWidget *widget);

private:
    ChoseBar *ch_bar;
    QHBoxLayout *layout;
    QHBoxLayout *placeLayout;

    QVector<QWidget *> *widgets;

private:
    void hideAll();

private slots:
    void showIndex(int index);

};

#endif // CENTRALWIDGET_H
