QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += ../test2/tas2.h
SOURCES +=  tst_t2.cpp ../test2/tas2.cpp
