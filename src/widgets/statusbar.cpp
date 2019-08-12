#include "statusbar.h"

StatusBar::StatusBar(QWidget *parent) : QStatusBar(parent)
{
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(BACKGROUND_COLOR));
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

StatusBar::~StatusBar(){

}
