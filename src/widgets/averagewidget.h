#ifndef AVERAGEWIDGET_H
#define AVERAGEWIDGET_H

#include "widgets/basewidget.h"
#include "processing/averaging.h"


class AverageWidget : public BaseWidget
{
public:
    AverageWidget(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);
};

#endif // AVERAGEWIDGET_H
