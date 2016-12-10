TEMPLATE = app

DESTDIR = $$PWD/bin

CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

include (opencv.pri)

CONFIG += precompile_header
PRECOMPILED_HEADER = src/pch.h

SOURCES += \
    src/main.cpp

HEADERS += \
    src/pch.h
