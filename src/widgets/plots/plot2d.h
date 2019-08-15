/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analitical data and processing experemental data
 */


#ifndef PLOT2D_H
#define PLOT2D_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QComboBox>

#include "plot.h"
#include "processing/neutrondata.h"

class Plot2D : public QWidget
{
    Q_OBJECT
public:
    explicit Plot2D(QWidget *parent = nullptr);

    void buildNeutronData(NeutronData *n_data);

protected:
    Plot *plot;

    QVBoxLayout *central_layout;
    QHBoxLayout *tool_layout;

    QDoubleSpinBox *spinBoxMax;
    QDoubleSpinBox *spinBoxMin;
    QCheckBox *check_hold;
    QCheckBox *check_log_scale;
    QComboBox *combo_select_units;

    QCPColorMap *colorMap;
    QCPColorScale *colorScale;


signals:

public slots:
    void logScale(bool state);
};

#endif // PLOT2D_H
