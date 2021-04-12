#-------------------------------------------------
#
# Project created by QtCreator 2019-09-29T21:25:02
#
#-------------------------------------------------

QT  += core gui
QT  += serialport
QT  += concurrent
QT  += charts
QT  += printsupport
QT  += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 7M30
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QCUSTOMPLOT_USE_OPENGL

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS+=-lopengl32 -lglu32

SOURCES += \
    dialog_chart.cpp \
    dialog_fig.cpp \
    dialog_thread1.cpp \
        main.cpp \
        mainwindow.cpp \
    dialog1.cpp \
    dialog2.cpp \
    dialog_advance.cpp \
    dialog_repeat.cpp \
    qcustomplot.cpp \
    threadobject.cpp

HEADERS += \
    dialog_chart.h \
    dialog_fig.h \
    dialog_thread1.h \
        mainwindow.h \
    qcustomplot.h \
    stable.h \
    dialog1.h \
    dialog2.h \
    dialog_advance.h \
    dialog_repeat.h \
    threadobject.h

FORMS += \
    dialog_chart.ui \
    dialog_fig.ui \
    dialog_thread1.ui \
    mainwindow.ui \
    dialog1.ui \
    dialog2.ui \
    dialog_advance.ui \
    dialog_repeat.ui

CONFIG += precompile_header
CONFIG += C++11
PRECOMPILED_HEADER = stable.h
RC_ICONS = 7m.ico

RESOURCES += \
    resource.qrc
