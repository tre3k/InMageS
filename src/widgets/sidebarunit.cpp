#include "sidebarunit.h"

SideBarUnit::SideBarUnit(QString text, QString image_path,QWidget *parent) : QWidget(parent)
{
    label = new QLabel();
    label_image = new QLabel();
    layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignHCenter);
    this->setLayout(layout);

    label_image->setAlignment(Qt::AlignHCenter);
    label->setAlignment(Qt::AlignHCenter);

    layout->addWidget(label_image);
    layout->addWidget(label);

    setText(text);
    setImage(image_path);

    setPalleteSelected();
}


void SideBarUnit::setText(QString text){
    label->setText("\n<b>"+text+"</b>");

}

void SideBarUnit::setImage(QString filepath){
    QPixmap image(filepath);
    label_image->setPixmap(image.scaled(50,50,Qt::KeepAspectRatioByExpanding));
}


/* SLOTS */

void SideBarUnit::setPalleteNormal(){
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor("#232323"));
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void SideBarUnit::setPalleteEnabled(){
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor("#131313"));
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void SideBarUnit::setPalleteSelected(){
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor("#535353"));
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}
