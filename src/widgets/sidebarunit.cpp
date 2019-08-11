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
    pAnimation->setDuration(1000);

    setText(text);
    setImage(image_path);

    setPalleteNormal();

    this->setMouseTracking(true);
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
    qDebug() << "press";
    setPalleteEnabled();
}

void SideBarUnit::mouseReleaseEvent(QMouseEvent *event){
    qDebug() << "release";
}

void SideBarUnit::mouseMoveEvent(QMouseEvent *event){
    if(this->rect().contains(event->pos())){
        setPalleteSelected();

    }else{
        //setPalleteNormal();
    }
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


/* SLOTS */
void SideBarUnit::setPalleteNormal(){
    /*
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor("#232323"));
    pal.setColor(QPalette::WindowText, QColor(Qt::white));

    this->setPalette(pal);
    */

    setColor("#232323");
}

void SideBarUnit::setPalleteEnabled(){
    /*
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor("#131313"));
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    */

    pAnimation->setStartValue("#232323");
    pAnimation->setEndValue("#535353");
    pAnimation->start();
}

void SideBarUnit::setPalleteSelected(){

    /*
    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor("#535353"));
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    */




}
