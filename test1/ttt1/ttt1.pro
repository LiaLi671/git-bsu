QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS +=../t2/tas1.h
SOURCES +=  tst_ttt1.cpp ../t2/tas1.cpp
