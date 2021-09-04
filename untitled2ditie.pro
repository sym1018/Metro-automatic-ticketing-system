#-------------------------------------------------
#
# Project created by QtCreator 2021-07-07T14:16:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled2ditie
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        widget.cpp \
    kaiguan.cpp \
    chufa.cpp \
    daoda.cpp \
    chupiao.cpp \
    Graph.cpp \
    m_list.cpp \
    Node.cpp \
    m_init.cpp

HEADERS += \
        widget.h \
    kaiguan.h \
    chufa.h \
    daoda.h \
    chupiao.h \
    Graph.h \
    m_list.h \
    Node.h \
    m_init.h

FORMS += \
        widget.ui

RESOURCES += \
    beijing.qrc
