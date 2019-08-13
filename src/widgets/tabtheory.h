#ifndef TABTHEORY_H
#define TABTHEORY_H

#include <QGridLayout>

#include "basewidget.h"
#include "plots/plot.h"

class TabTheory : public BaseWidget
{
    Q_OBJECT
public:
    explicit TabTheory(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);

private:
    QGridLayout *top_layout;
    Plot *plot_average;

signals:

public slots:
};

#endif // TABTHEORY_H
