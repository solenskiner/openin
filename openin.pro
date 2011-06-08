#-------------------------------------------------
#
# Project created by QtCreator 2011-03-05T12:37:58
#
#-------------------------------------------------

QT       += core gui


CONFIG = \
    qt \
    clang \
    debug
 #   release

TARGET = openin
TEMPLATE = app

SOURCES += main.cpp\
    findbrowser.cpp \
    mainwindow.cpp \
    browsericon.cpp

HEADERS  += mainwindow.hpp \
    findbrowser.hpp \
    browsericon.hpp \
    iconsize.hpp

OBJECTS_DIR = /tmp/
MOC_DIR = /tmp/

RELEASEFLAGS += \
#    -O4 \
    -O3 \
    -fomit-frame-pointer \
    -march=x86-64 \
#    -flto \
#    -fwhole-program \
    -ffast-math
DEBUGFLAGS += \
    -O0 \
    -ggdb \
    -pedantic \
    -W \
    -Wall \
    -Wextra \
    -Wuninitialized \
    -Wshadow \
    -Wsign-compare \
    -Wwrite-strings \
    -Wunused \
    -Wfloat-equal \
    -Wmissing-declarations \
    -Wunreachable-code \
    -Wcast-qual \
    -ftrapv \
#    -fcatch-undefined-behavior

QMAKE_LFLAGS_RELEASE = $$RELEASEFLAGS
QMAKE_LFLAGS_DEBUG = $$DEBUGFLAGS
QMAKE_CFLAGS_GENERIC = \
    -std=c99 \
    -Wc++-compat \
    -pipe
QMAKE_CFLAGS_RELEASE = \
    $$QMAKE_CFLAGS_GENERIC \
    $$RELEASEFLAGS
QMAKE_CFLAGS_DEBUG = \
    $$QMAKE_CFLAGS_GENERIC \
    $$DEBUGFLAGS
QMAKE_CXXFLAGS_GENERIC = \
   -std=c++98 \
    -pipe
QMAKE_CXXFLAGS_RELEASE = \
    $$QMAKE_CXXFLAGS_GENERIC \
    $$RELEASEFLAGS
QMAKE_CXXFLAGS_DEBUG = \
    $$QMAKE_CXXFLAGS_GENERIC \
    $$DEBUGFLAGS

QMAKE_CC = gcc
QMAKE_CXX = g++
CONFIG(clang) {
    QMAKE_CC = clang
    QMAKE_CXX = clang
}
