/* mainwindow.h
 * Copyright 2019 Aug
 * Kirill Pshenichnyi
 * This part of InMageS (Inelastic Magnet Scattering)
 * Software for Build analytical data and processing experemental data
 */

#include "tabopen.h"

TabOpen::TabOpen(StatusBarThread *sbt, QWidget *parent) : BaseWidget(sbt,parent)
{
    auto tab_widget = new QTabWidget();
    auto top_layout = new QVBoxLayout();

    auto open_raw_file_widget = new OpenRawFileWidget(sbt);
    auto open_db_widget = new OpenDBWidget(sbt);

    tab_widget->addTab(open_raw_file_widget,"Open raw file");
    tab_widget->addTab(open_db_widget, "Database");

    top_layout->addWidget(tab_widget);

    this->setLayout(top_layout);
}
