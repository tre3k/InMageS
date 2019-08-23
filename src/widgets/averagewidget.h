#ifndef AVERAGEWIDGET_H
#define AVERAGEWIDGET_H


#include <QVector>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>

#include "widgets/basewidget.h"
#include "processing/averaging.h"
#include "threads/averagethread.h"


class AverageWidget : public BaseWidget
{
    Q_OBJECT
public:
    AverageWidget(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);
    ~AverageWidget();

private:
    QVector<AverageThread *> a_threads;

    /* Widgets */
    QPushButton *button_average;
    QPushButton *button_add;
    QPushButton *button_rm;
    QComboBox *combo_select;

    QDoubleSpinBox *spinBox_angle;
    QDoubleSpinBox *spinBox_open_angle;
    QDoubleSpinBox *spinBox_pos_x;
    QDoubleSpinBox *spinBox_pos_y;
    QDoubleSpinBox *spinBox_lenght;
    QDoubleSpinBox *spinBox_offset;

    QVBoxLayout *layout_top;
    QHBoxLayout *layout_combo;

public slots:
    void addAverageThread(AverageThread *average_thread);


};

#endif // AVERAGEWIDGET_H
