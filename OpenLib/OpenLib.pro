TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Exception.cpp \
        Object.cpp \
        main.cpp

HEADERS += \
    Exception.h \
    List.h \
    Object.h \
    SeqList.h \
    SmartPointer.h
