QT += \
  core \
  gui \
  widgets

TARGET = inmages
TEMPLATE = app

SOURCES += \
        processing/indata.cpp \
        main.cpp \
        mainwindow.cpp \
        threads/statusbarthread.cpp \
        widgets/basewidget.cpp \
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
        processing/indata.h \
        mainwindow.h \
        threads/statusbarthread.h \
        widgets/basewidget.h \
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
