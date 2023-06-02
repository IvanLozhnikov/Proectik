QT += testlib network sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_func_for_server_test.cpp \
    SingletonDB.cpp \
    func_for_server.cpp \
    mytcpserver.cpp

HEADERS += \
    Singleton.h \
    SingletonDB.h \
    func_for_server.h \
    mytcpserver.h

DISTFILES += \
    Dockerfile \
    README.md \
    sqlite.db
