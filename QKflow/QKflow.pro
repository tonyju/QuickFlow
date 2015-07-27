#-------------------------------------------------
#
# Project created by QtCreator 2015-07-11T16:06:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QKflow
TEMPLATE = app


SOURCES += main.cpp\
        qkflow.cpp \
    PnGraphics/pnbar.cpp \
    PnGraphics/pnview.cpp \
    PnGraphics/pnslack.cpp \
    PnGraphics/pnpq.cpp \
    PnGraphics/pnpv.cpp \
    PnGraphics/pnline.cpp \
    PnGraphics/pncable.cpp

HEADERS  += qkflow.h \
    PnGraphics/pnbar.h \
    PnGraphics/pnview.h \
    PnGraphics/pnslack.h \
    PnGraphics/pnpq.h \
    PnGraphics/pnpv.h \
    PnGraphics/pnline.h \
    PnGraphics/pncable.h

FORMS    += qkflow.ui

RESOURCES += \
    img.qrc \
    PnGraphics/pnrc.qrc
