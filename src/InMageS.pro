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
        processing/averaging.cpp \
        processing/data2d.cpp \
        processing/neutrondata.cpp \
        processing/theory.cpp \
        threads/averagethread.cpp \
        threads/statusbarthread.cpp \
        widgets/averagewidget.cpp \
        widgets/basewidget.cpp \
        widgets/opendbwidget.cpp \
        widgets/openrawfilewidget.cpp \
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
        widgets/tabtheory.cpp \
        widgets/theorywidget.cpp

HEADERS += \
        mainwindow.h \
        processing/averaging.h \
        processing/data2d.h \
        processing/neutrondata.h \
        processing/theory.h \
        threads/averagethread.h \
        threads/statusbarthread.h \
        widgets/averagewidget.h \
        widgets/basewidget.h \
        widgets/opendbwidget.h \
        widgets/openrawfilewidget.h \
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
        widgets/tabtheory.h \
        widgets/theorywidget.h

RESOURCES += \
        resources.qrc
