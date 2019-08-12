#ifndef TABHELP_H
#define TABHELP_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class TabHelp : public QWidget
{
    Q_OBJECT
public:
    explicit TabHelp(QWidget *parent = nullptr);

private:
    QVBoxLayout *layout;

signals:

public slots:
};

#endif // TABHELP_H
