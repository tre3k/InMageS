#ifndef CHOSEBAR_H
#define CHOSEBAR_H

#include <QWidget>
#include <QListWidget>


/* Part of the main widget aka tabs */
class ChoseBar : public QListWidget
{
    Q_OBJECT
public:
    ChoseBar(QWidget *parent = nullptr);
    ~ChoseBar();
};

#endif // CHOSEBAR_H
