/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#include "averagewidget.h"

AverageWidget::AverageWidget(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt, parent)
{
    status_bar_thread = sbt;

    button_add = new QPushButton("+");
    button_rm = new QPushButton("-");
    button_average = new QPushButton("average");
    button_set = new QPushButton("set");
    combo_select = new QComboBox(this);

    layout_combo = new QHBoxLayout();
    layout_combo->addWidget(combo_select);
    layout_combo->addWidget(button_add);
    layout_combo->addWidget(button_rm);

    button_rm->setMaximumWidth(30);
    button_add->setMaximumWidth(30);

    combo_untis = new QComboBox(this);
    combo_untis->addItem("pixels");
    combo_untis->addItem("wave vector [1/Å]");
    combo_untis->addItem("wave vector [1/nm]");
    combo_untis->addItem("angle θ [mrad]");
    combo_untis->addItem("reletiv [-1;1]");

    /*spinBoxs*/
    spinBox_angle = new QDoubleSpinBox();
    spinBox_angle->setSuffix(" degree");
    spinBox_angle->setRange(-360.0, 360.0);
    spinBox_lenght = new QDoubleSpinBox();
    spinBox_lenght->setRange(0,1);
    spinBox_lenght->setSingleStep(0.01);
    spinBox_open_angle = new QDoubleSpinBox();
    spinBox_open_angle->setSuffix(" degree");
    spinBox_open_angle->setRange(-360.0, 360.0);
    spinBox_offset = new QDoubleSpinBox();
    spinBox_offset->setRange(0,1);
    spinBox_offset->setSingleStep(0.01);

    spinBox_pos_x = new QDoubleSpinBox();
    spinBox_pos_x->setRange(-1,1);
    spinBox_pos_x->setDecimals(3);
    spinBox_pos_x->setSingleStep(0.01);
    spinBox_pos_y = new QDoubleSpinBox();
    spinBox_pos_y->setRange(-1,1);
    spinBox_pos_y->setDecimals(3);
    spinBox_pos_y->setSingleStep(0.01);

    auto *layout_elements = new QFormLayout();
    layout_elements->addRow("Angle: ",spinBox_angle);
    layout_elements->addRow("Open angle: ",spinBox_open_angle);
    layout_elements->addRow("Lenght: ",spinBox_lenght);
    layout_elements->addRow("Offset: ",spinBox_offset);
    auto *layout_position = new QHBoxLayout();
    layout_position->addWidget(spinBox_pos_x);
    layout_position->addWidget(spinBox_pos_y);
    layout_elements->addRow("Center position x,y: ",layout_position);
    auto *layout_buttons = new QHBoxLayout();
    layout_buttons->addWidget(button_set);
    layout_buttons->addWidget(button_average);
    layout_elements->addRow("",layout_buttons);
    layout_elements->addRow("Units on 'x' axie: ",combo_untis);

    layout_top = new QVBoxLayout();
    layout_top->addLayout(layout_combo);
    layout_top->addLayout(layout_elements);

    auto g_box = new QGroupBox("Average: ");
    auto layout = new QVBoxLayout();
    this->setLayout(layout);
    layout->addWidget(g_box);
    g_box->setLayout(layout_top);

    a_threads.clear();


    connect(combo_select,SIGNAL(activated(int)),this,SLOT(setUIFromAveraging(int)));
    connect(button_set,SIGNAL(clicked()),this,SLOT(pressButtonSet()));
    connect(button_rm,SIGNAL(clicked()),this,SLOT(pressButtonRm()));
    connect(button_add,SIGNAL(clicked()),this,SLOT(pressButtonAdd()));
    connect(button_average,SIGNAL(clicked()),this,SLOT(pressButtonAverage()));
    //connect(combo_select,SIGNAL())

}

AverageWidget::~AverageWidget(){

}


void AverageWidget::addAverageThread(AverageThread *average_thread){
    if(nd!=nullptr) average_thread->setNutronData(nd);
    combo_select->addItem(average_thread->getName());
    a_threads.append(average_thread);
    average_thread->setNumber(a_threads.size()-1);
    //setUIFromAveraging(a_threads.size()-1);

    connect(average_thread,SIGNAL(endProcessing(int)),this,SLOT(plotData(int)));

    combo_select->activated(a_threads.size()-1);
    combo_select->setCurrentIndex(a_threads.size()-1);
    return;
}

void AverageWidget::setUIFromAveraging(int index){
    /* may be need make convert units */
    spinBox_angle->setValue(a_threads.at(index)->av->getAngle());
    spinBox_open_angle->setValue(a_threads.at(index)->av->getOpenAngle());
    spinBox_lenght->setValue(a_threads.at(index)->av->getLength());
    spinBox_offset->setValue(a_threads.at(index)->av->getOffset());
    spinBox_pos_x->setValue(a_threads.at(index)->av->getX0());
    spinBox_pos_y->setValue(a_threads.at(index)->av->getY0());
}

void AverageWidget::setAveragingFromUI(){
    a_threads.at(combo_select->currentIndex())->av->setAngle(spinBox_angle->value());
    a_threads.at(combo_select->currentIndex())->av->setOpenAngle(spinBox_open_angle->value());
    a_threads.at(combo_select->currentIndex())->av->setLenght(spinBox_lenght->value());
    a_threads.at(combo_select->currentIndex())->av->setOffset(spinBox_offset->value());
    a_threads.at(combo_select->currentIndex())->av->setX0(spinBox_pos_x->value());
    a_threads.at(combo_select->currentIndex())->av->setY0(spinBox_pos_y->value());

    /* paint symbols on 2dplot, here for test*/

}

void AverageWidget::pressButtonAverage(){
    //setAveragingFromUI();    // or...?
    pressButtonSet();
    p1d->getPlot()->clearGraphs();
    for(int i=0;i<a_threads.size();i++){
        qDebug() << "start " << i << " therad";
        if(a_threads.at(i)!=nullptr) a_threads.at(i)->start();
    }
    return;
}

void AverageWidget::pressButtonAdd(){
    bool ok;
    QString default_name = "average"+QString::number(a_threads.size()+1);
    QString name = QInputDialog::getText(this, "set name: ",
                                         "Name: ", QLineEdit::Normal,
                                         default_name, &ok);
    if(ok && !name.isEmpty()){
        auto *average_thread = new AverageThread();
        average_thread->setName(name);
        this->addAverageThread(average_thread);
        renumbersThreads();
    }

}


void AverageWidget::pressButtonRm(){
    disconnect(a_threads.at(combo_select->currentIndex()),SIGNAL(endProcessing(int)),this,SLOT(plotData(int)));

    delete a_threads.at(combo_select->currentIndex());
    a_threads.removeAt(combo_select->currentIndex());
    renumbersThreads();

    combo_select->removeItem(combo_select->currentIndex());
}

void AverageWidget::plotData(int num){
    QVector<double> xTheta,xAngstorm,xNanoMeters,xrel,y;
    double rel;
    double *data = a_threads.at(num)->av->getResult();
    double dc = (a_threads.at(num)->av->getLength()-a_threads.at(num)->av->getOffset())/a_threads.at(num)->av->getResultSize();
    if(data==nullptr) return;
    for(int i=0;i<a_threads.at(num)->av->getResultSize();i++){
        rel = a_threads.at(num)->av->getOffset()+dc*i;
        xrel.append(rel);
        xTheta.append(rel*nd->getMaximumThetaXmrad());
        xAngstorm.append(rel*nd->get_maxQx_A());
        xNanoMeters.append(rel*nd->get_maxQx_nm());
        y.append(data[i]);
    }

    QString color;
    switch(num){
    case 0:
        color = "#1212f5";          // blue
        break;
    case 1:
        color = "#f51212";          // red
        break;
    case 2:
        color = "#12f512";          // green
        break;
    case 3:
        color = "#edf512";          // yellow
        break;
    default:
        color = "rand";
        break;
    }
    switch (combo_untis->currentIndex()) {
    case UNIT_NM:
        p1d->addPlot(xNanoMeters,y,a_threads.at(num)->getName(),color);
        break;
    case UNIT_ANGSTROM:
        p1d->addPlot(xAngstorm,y,a_threads.at(num)->getName(),color);
        break;
    case UNIT_THETA:
        p1d->addPlot(xTheta,y,a_threads.at(num)->getName(),color);
        break;
    default:
        p1d->addPlot(xrel,y,a_threads.at(num)->getName(),color);
        break;
    }

    p1d->getPlot()->legend->setVisible(true);
    p1d->rescaleAxis();
}

/* for remove and add new average item */
void AverageWidget::renumbersThreads(){
    for(int i=0;i<a_threads.size();i++){
        a_threads.at(i)->setNumber(i);
    }
}

void AverageWidget::pressButtonSet(){
    setAveragingFromUI();

    p2d->rescaleAxis();
    p2d->getPlot()->clearItems();
    for(int i=0;i<a_threads.size();i++){
        paintCross(p2d->getRecoordX(a_threads.at(i)->av->getX0()),
                   p2d->getRecoordY(a_threads.at(i)->av->getY0()));
        paintSector(p2d->getRecoordX(a_threads.at(i)->av->getX0()),
                    p2d->getRecoordY(a_threads.at(i)->av->getY0()),
                    a_threads.at(i)->av->getAngle(),
                    a_threads.at(i)->av->getOpenAngle(),
                    p2d->getRecoordX(a_threads.at(i)->av->getOffset()),
                    p2d->getRecoordX(a_threads.at(i)->av->getLength()));

    }

    p2d->getPlot()->replot();
}

void AverageWidget::paintCross(double x,double y,double scale){
    double scale_x = scale;
    double scale_y = scale;

    scale_x *= (p2d->getPlot()->xAxis->range().upper - p2d->getPlot()->xAxis->range().lower);
    scale_y *= (p2d->getPlot()->yAxis->range().upper - p2d->getPlot()->yAxis->range().lower);

    auto line1 = new QCPItemLine(p2d->getPlot());
    line1->setPen(QPen(QColor("black"),1,Qt::SolidLine,Qt::SquareCap,Qt::BevelJoin));
    line1->start->setCoords(x,y+scale_y);
    line1->end->setCoords(x,y-scale_y);

    auto line2 = new QCPItemLine(p2d->getPlot());
    line2->setPen(QPen(QColor("black"),1,Qt::SolidLine,Qt::SquareCap,Qt::BevelJoin));
    line2->start->setCoords(x+scale_x,y);
    line2->end->setCoords(x-scale_x,y);
}

void AverageWidget::paintSector(double x0, double y0, double angle, double open_angle, double offset, double length){
    double x,y;

    auto line1 = new QCPItemLine(p2d->getPlot());
    line1->setPen(QPen(QColor("white"),1,Qt::SolidLine,Qt::SquareCap,Qt::BevelJoin));
    Averaging::toDecart(offset,angle+open_angle/2,&x,&y);
    line1->start->setCoords(x+x0,y+y0);
    Averaging::toDecart(length,angle+open_angle/2,&x,&y);
    line1->end->setCoords(x+x0,y+y0);

    auto line2 = new QCPItemLine(p2d->getPlot());
    line2->setPen(QPen(QColor("white"),1,Qt::SolidLine,Qt::SquareCap,Qt::BevelJoin));
    Averaging::toDecart(offset,angle-open_angle/2,&x,&y);
    line2->start->setCoords(x+x0,y+y0);
    Averaging::toDecart(length,angle-open_angle/2,&x,&y);
    line2->end->setCoords(x+x0,y+y0);

    auto line3 = new QCPItemCurve(p2d->getPlot());
    line3->setPen(QPen(QColor("white"),1,Qt::SolidLine,Qt::SquareCap,Qt::BevelJoin));
    Averaging::toDecart(length,angle+open_angle/2,&x,&y);
    line3->start->setCoords(x+x0,y+y0);
    Averaging::toDecart(length,angle+20,&x,&y);
    line3->startDir->setCoords(x+x0,y+y0);
    Averaging::toDecart(length,angle-open_angle/2,&x,&y);
    line3->end->setCoords(x+x0,y+y0);
    Averaging::toDecart(length,angle-20,&x,&y);
    line3->endDir->setCoords(x+x0,y+y0);
}
