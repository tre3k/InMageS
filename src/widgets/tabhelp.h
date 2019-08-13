#ifndef TABHELP_H
#define TABHELP_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

#include "basewidget.h"

class TabHelp : public BaseWidget
{
    Q_OBJECT
public:
    explicit TabHelp(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;
    QPushButton *helpButton;

signals:

public slots:
    void helpButtonClick();
};

#endif // TABHELP_H
