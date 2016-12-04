TEMPLATE = app

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include (opencv.pri)

SOURCES += \
    src/main.cpp
