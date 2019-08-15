QT += \
       core \
       gui \
       widgets \
       printsupport

TARGET = inmages
TEMPLATE = app

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        processing/data2d.cpp \
        processing/neutrondata.cpp \
        processing/swtheory.cpp \
        threads/statusbarthread.cpp \
        widgets/basewidget.cpp \
        widgets/plots/plot.cpp \
        widgets/plots/plot1d.cpp \
        widgets/plots/plot2d.cpp \
        widgets/plots/qcustomplot.cpp \
        widgets/tabhelp.cpp \
        widgets/tabopen.cpp \
        widgets/centralwidget.cpp \
        widgets/sidebar.cpp \
        widgets/sidebarunit.cpp \
        widgets/statusbar.cpp \
        widgets/tabprocessing.cpp \
        widgets/tabsave.cpp \
        widgets/tabtheory.cpp

HEADERS += \
        mainwindow.h \
        processing/data2d.h \
        processing/neutrondata.h \
        processing/swtheory.h \
        threads/statusbarthread.h \
        widgets/basewidget.h \
        widgets/plots/plot.h \
        widgets/plots/plot1d.h \
        widgets/plots/plot2d.h \
        widgets/plots/qcustomplot.h \
        widgets/tabhelp.h \
        widgets/tabopen.h \
        widgets/centralwidget.h \
        widgets/sidebar.h \
        widgets/sidebarunit.h \
        widgets/statusbar.h \
        widgets/tabprocessing.h \
        widgets/tabsave.h \
        widgets/tabtheory.h

RESOURCES += \
        resources.qrc
