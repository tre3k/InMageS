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
        widgets/sidebarunit.cpp

HEADERS += \
        processing/indata.h \
        mainwindow.h \
        widgets/centralwidget.h \
        widgets/sidebar.h \
        widgets/sidebarunit.h

RESOURCES += \
    resources.qrc
