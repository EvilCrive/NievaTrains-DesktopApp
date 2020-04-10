TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bolletta.cpp \
        main.cpp \
        orario.cpp \
        telefonata.cpp \
        testing_main.cpp

HEADERS += \
    bolletta.h \
    orario.h \
    telefonata.h \
    testing_main.h
