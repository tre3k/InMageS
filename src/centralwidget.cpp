#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent){
    layout = new QHBoxLayout();
    ch_bar = new ChoseBar();
    widgets = new QVector<QWidget *>;

    layout->addWidget(ch_bar);
    this->setLayout(layout);

    connect(ch_bar,SIGNAL(currentRowChanged(int)),
            this,SLOT(showIndex(int)));

}

CentralWidget::~CentralWidget(){
    delete layout;
    delete ch_bar;
    delete widgets;
}

void CentralWidget::addTab(QString name, QWidget *widget){
    ch_bar->addItem(name);
    layout->addWidget(widget);
    widget->hide();
    widgets->append(widget);
}

void CentralWidget::showIndex(int index){
    hideAll();
    if(index < widgets->size()){
        widgets->at(index)->show();
    }
    return;
}

void CentralWidget::hideAll(){
    for(int i=0;i<widgets->size();i++){
        widgets->at(i)->hide();
    }
}


