/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#include "sidebarunit.h"

SideBarUnit::SideBarUnit(QString text, QString image_path_normal, QString image_path_active,QWidget *parent) : QWidget(parent)
{
    /* initilization */
    label = new QLabel();
    label_image = new QLabel();
    layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignHCenter);
    this->setLayout(layout);

    label_image->setAlignment(Qt::AlignHCenter);
    label->setAlignment(Qt::AlignHCenter);

    layout->addWidget(label_image);
    layout->addWidget(label);

    pAnimation = new QPropertyAnimation(this,"color");
    pAnimation->setDuration(DURATION_ANIMATION);

    setText(text);
    setImage(image_path_normal);

    image_file_active = image_path_active;
    image_file_normal = image_path_normal;

    this->setMouseTracking(false);
    this->setAutoFillBackground(true);

    // set background color also as sidebar RGB #434343
    setPalleteNormal();
}


void SideBarUnit::setText(QString text){
    label->setText("\n<b>"+text+"</b>");

}

void SideBarUnit::setImage(QString filepath){
    QPixmap image(filepath);
    label_image->setPixmap(image.scaled(50,50,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    //label_image->setPixmap(image);
}

void SideBarUnit::mousePressEvent(QMouseEvent *event){
    setPalleteEnabled();
    emit clicked(n_index);
}

void SideBarUnit::mouseReleaseEvent(QMouseEvent *event){
    /* RESERVATION */
}

void SideBarUnit::mouseMoveEvent(QMouseEvent *event){
    /* RESERVATION */
}

void SideBarUnit::setColor(QColor color){
    QPalette pal(palette());
    pal.setColor(QPalette::Background, color);
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

QColor SideBarUnit::color(){
    return Qt::black;
}

void SideBarUnit::setIndex(int index){
    n_index = index;
}

int SideBarUnit::getIndex(){
    return n_index;
}

/* SLOTS */
void SideBarUnit::setPalleteNormal(){
    pAnimation->stop();
    setImage(image_file_normal);
    setColor(BACKGROUND_COLOR);
}

void SideBarUnit::setPalleteEnabled(){
    setImage(image_file_active);
    pAnimation->setStartValue(BACKGROUND_COLOR);
    pAnimation->setEndValue(BACKLIGHT_COLOR);
    pAnimation->start();
}

void SideBarUnit::setPalleteSelectedWithoutAnimation(){
    setImage(image_file_active);
    setColor(QColor(BACKLIGHT_COLOR));
}

void SideBarUnit::setPalleteSelected(){
    /* RESERVATION */

}
