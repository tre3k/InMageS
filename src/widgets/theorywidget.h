#ifndef THEORYWIDGET_H
#define THEORYWIDGET_H

#include <QFormLayout>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QFormLayout>
#include <QHBoxLayout>

#include "widgets/basewidget.h"
#include "processing/neutrondata.h"
#include "processing/theory.h"
#include "widgets/plots/plot2d.h"

enum TheoryType{
    THEORY_TYPE_FERROMAGNET,
    THEORY_TYPE_HELICOMAGNET
};

class TheoryWidget : public BaseWidget
{
    Q_OBJECT
public:
    TheoryWidget(StatusBarThread *sbt=NULL, QWidget *parent = nullptr);
    ~TheoryWidget(){return;}

    void setNeutronData(NeutronData *neutron_data){nd = neutron_data;}
    void setPlot2D(Plot2D *plot_2d){p2d = plot_2d;}

    /* set Neutron Data and Plot2D */
    void setNdPl(NeutronData *neutron_data,
                 Plot2D *plot_2d){
        setNeutronData(neutron_data);
        setPlot2D(plot_2d);
    }

private:
    Plot2D *p2d;
    NeutronData *nd;

    /* widgets */
    QFormLayout *layout;
    QComboBox *comboSelectType;
    QDoubleSpinBox *spinBox_stiffness;          // spin-wave stiffness
    QDoubleSpinBox *spinBox_field;              // magnet field
    QDoubleSpinBox *spinBox_ks;                 // spiral wave vector
    QDoubleSpinBox *spinBox_lambda;             // wave lenght
    QDoubleSpinBox *spinBox_Dsd;                // distance source detector
    QDoubleSpinBox *spinBox_px, *spinBox_py;    // detector resolution (pixel size)
    QSpinBox *spinBox_Nx, *spinBox_Ny;          // size of detector in pixels
    QPushButton *button_build;

public slots:
    /* calculate and build plot */
    void build(void);

};

#endif // THEORYWIDGET_H
