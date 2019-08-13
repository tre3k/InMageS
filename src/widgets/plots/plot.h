#ifndef PLOT_H
#define PLOT_H

#include "qcustomplot.h"

class Plot : public QCustomPlot
{
    Q_OBJECT
public:
    Plot(QWidget *parent=nullptr);
    ~Plot();

private slots:
    void slot_sAxies_drag_zoom(QCPAxis *,QCPAxis::SelectablePart,QMouseEvent *);
    void slot_full_drag_zoom(QMouseEvent *);
    void slot_selectionChanged();
    void slot_contextMenuReq(QPoint p);

    void exportToPDF();
    void exportToBMP();
    void exportToJPG();
    void exportToPNG();

};

#endif // PLOT_H
