QT += core
QT -= gui

CONFIG += c++11

TARGET = LogisticRegression
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    settraining.cpp \
    hypothesis.cpp \
    gradientdescent.cpp \
    costfunction.cpp

win32 {
    INCLUDEPATH += C:/boost/include/boost-1_66
    LIBS += "-LC:/boost\lib" \
            "-Llibboost_filesystem-mgw49-mt-d-x32-1_66.a" \
            "-Llibboost_serialization-mgw49-mt-d-x32-1_66.a" \
            "-Llibboost_system-mgw49-mt-d-x32-1_66.a" -LLIBS
}

HEADERS += \
    settraining.h \
    hypothesis.h \
    gradientdescent.h \
    costfunction.h
