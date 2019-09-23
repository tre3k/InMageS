/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */

#ifndef AVERAGEWIDGET_H
#define AVERAGEWIDGET_H


#include <QVector>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QInputDialog>

#include "widgets/basewidget.h"
#include "processing/averaging.h"
#include "threads/averagethread.h"
#include "plots/plot2d.h"
#include "plots/plot1d.h"


class AverageWidget : public BaseWidget
{
    Q_OBJECT
public:
    AverageWidget(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);
    ~AverageWidget();

private:
    QVector<AverageThread *> a_threads;
    NeutronData *nd = nullptr;

    Plot2D *p2d = nullptr;  // for paint lines
    Plot1D *p1d = nullptr;  // for plot results

    StatusBarThread *status_bar_thread;

    /* Widgets */
    QPushButton *button_average;
    QPushButton *button_set;
    QPushButton *button_add;
    QPushButton *button_rm;
    QComboBox *combo_select;

    QDoubleSpinBox *spinBox_angle;
    QDoubleSpinBox *spinBox_open_angle;
    QDoubleSpinBox *spinBox_pos_x;
    QDoubleSpinBox *spinBox_pos_y;
    QDoubleSpinBox *spinBox_lenght;
    QDoubleSpinBox *spinBox_offset;

    QComboBox *combo_untis;

    QVBoxLayout *layout_top;
    QHBoxLayout *layout_combo;

    void renumbersThreads();
    void paintCross(double x,double y,double scale = 0.01);
    void paintSector(double x0,double y0,double angle,double open_angle,double offset,double length);

public slots:
    void addAverageThread(AverageThread *average_thread);
    void setUIFromAveraging(int index);
    void setAveragingFromUI(void);

    void setNeutronData(NeutronData *neutron_data){
        nd = neutron_data;
        for(int i=0;i<a_threads.size();i++){
            a_threads.at(i)->av->setNeutronData(nd);
        }
    }
    void setPlot1D(Plot1D *plot1d){p1d = plot1d;}
    void setPlot2D(Plot2D *plot2d){p2d = plot2d;}


    void pressButtonSet(void);
    void pressButtonAverage(void);

    void pressButtonAdd(void);
    void pressButtonRm(void);

    void plotData(int num);

};

#endif // AVERAGEWIDGET_H
