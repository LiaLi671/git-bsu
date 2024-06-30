QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += ../p_test3/task3.h
SOURCES +=  tst_m_t3.cpp ../p_test3/task3.cpp
