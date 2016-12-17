QT += core
QT -= gui

TARGET = bridgemode
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Abstraction.cpp \
    AbstractImplement.cpp

HEADERS += \
    Abstraction.h \
    AbstractImplement.h

