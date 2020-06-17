#-------------------------------------------------
#
# Project created by QtCreator 2015-09-16T08:10:25
#
#-------------------------------------------------

QT       += core gui
QT += printsupport
QT += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -fopenmp
QMAKE_LFLAGS +=  -fopenmp
QMAKE_CFLAGS_RELEASE += -fopenmp

TARGET = CroCo
TEMPLATE = app
LIBS += -larmadillo
LIBS += -lcfitsio
LIBS += -lCCfits
LIBS += -lm
LIBS += -lstdc++
LIBS += -lgomp
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
    arithmetic.cpp \
    crop.cpp \
    splinefit.cpp \
    blazecorr.cpp \
    moments.cpp \
    vald3.cpp

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
    arithmetic.h \
    crop.h \
    splinefit.h \
    massega.h \
    blazecorr.h \
    moments.h \
    vald3.h

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
    arithmetic.ui \
    crop.ui \
    splinefit.ui \
    blazecorr.ui \
    moments.ui \
    vald3.ui

RESOURCES += \
    images.qrc
