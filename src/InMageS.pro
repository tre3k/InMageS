QT += \
  core \
  gui \
  widgets

TARGET = inmages
TEMPLATE = app

SOURCES += \
        indata.cpp \
        main.cpp \
        mainwindow.cpp \
        widgets/sidebar.cpp

HEADERS += \
        indata.h \
        mainwindow.h \
        widgets/sidebar.h

RESOURCES += \
    resources.qrc
