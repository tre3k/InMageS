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
        widgets/centralwidget.cpp \
        widgets/sidebar.cpp \
        widgets/sidebarunit.cpp \
        widgets/statusbar.cpp

HEADERS += \
        processing/indata.h \
        mainwindow.h \
        widgets/centralwidget.h \
        widgets/sidebar.h \
        widgets/sidebarunit.h \
        widgets/statusbar.h

RESOURCES += \
    resources.qrc
