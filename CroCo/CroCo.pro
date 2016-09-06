#-------------------------------------------------
#
# Project created by QtCreator 2015-09-16T08:10:25
#
#-------------------------------------------------

QT       += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CroCo
TEMPLATE = app
LIBS += -lcfitsio
LIBS += -lCCfits
LIBS += -lm
LIBS += -lstdc++
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    plotspec.cpp \
    plotsequ.cpp \
    rvcurve.cpp \
    template.cpp \
    binarytool.cpp \
    telluric.cpp \
    mapplot.cpp \
    rvcalc.cpp \
    rename.cpp \
    cpd.cpp \
    arithmetic.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    plotspec.h \
    plotsequ.h \
    rvcurve.h \
    template.h \
    binarytool.h \
    telluric.h \
    mapplot.h \
    rvcalc.h \
    rename.h \
    cpd.h \
    arithmetic.h

FORMS    += mainwindow.ui \
    plotspec.ui \
    plotsequ.ui \
    rvcurve.ui \
    template.ui \
    binarytool.ui \
    telluric.ui \
    mapplot.ui \
    rvcalc.ui \
    rename.ui \
    cpd.ui \
    arithmetic.ui

RESOURCES += \
    images.qrc
