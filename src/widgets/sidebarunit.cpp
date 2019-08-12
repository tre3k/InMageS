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

    pAnimation = new QPropertyAnimation(this,"color");
    pAnimation->setDuration(100);

    setText(text);
    setImage(image_path);

    setPalleteNormal();

    this->setMouseTracking(false);
    this->setAutoFillBackground(true);
}


void SideBarUnit::setText(QString text){
    label->setText("\n<b>"+text+"</b>");

}

void SideBarUnit::setImage(QString filepath){
    QPixmap image(filepath);
    label_image->setPixmap(image.scaled(50,50,Qt::KeepAspectRatioByExpanding));
}

void SideBarUnit::mousePressEvent(QMouseEvent *event){
    setPalleteEnabled();
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
    setColor("#434343");
}

void SideBarUnit::setPalleteEnabled(){
    pAnimation->setStartValue("#434343");
    pAnimation->setEndValue("#131313");
    pAnimation->start();
}

void SideBarUnit::setPalleteSelected(){
    /* RESERVATION */

}
