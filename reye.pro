TEMPLATE = app

DESTDIR = $$PWD/bin

CONFIG += console c++11
CONFIG -= app_bundle

include (opencv.pri)

CONFIG += precompile_header
PRECOMPILED_HEADER = src/pch.h

SOURCES += \
    src/main.cpp

HEADERS += \
    src/pch.h \
    src/version.h \
    src/capture.h \
    src/inc.h \
    src/mouse_draw.h \
    src/threshold.h \
    src/circle_finder.h \
    src/warp_affine.h
