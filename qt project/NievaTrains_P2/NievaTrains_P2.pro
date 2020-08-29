QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    model/model.cpp \
    model/gerarchia/bimode.cpp \
    model/gerarchia/electric.cpp \
    model/gerarchia/internal_combustion.cpp \
    model/gerarchia/maglev.cpp \
    model/gerarchia/steam.cpp \
    model/gerarchia/treno.cpp \
    view/aggiuntalayout.cpp \
    view/supporto/comboboxmotoreprimario.cpp \
    view/supporto/comboboxtech.cpp \
    view/supporto/comboboxtrasmissione.cpp \
    view/supporto/combofilter.cpp \
    view/supporto/combotype.cpp \
    view/infolayout.cpp \
    view/mainlayout.cpp \
    view/mainwindow.cpp \
    view/menubartrain.cpp \
    view/supporto/nievaexception.cpp \
    view/modificalayout.cpp \
    view/supporto/trainlist.cpp

HEADERS += \
    Qontainer.h \
    model/model.h \
    model/gerarchia/bimode.h \
    model/gerarchia/electric.h \
    model/gerarchia/internal_combustion.h \
    model/gerarchia/maglev.h \
    model/gerarchia/steam.h \
    model/gerarchia/treno.h \
    view/aggiuntalayout.h \
    view/supporto/comboboxmotoreprimario.h \
    view/supporto/comboboxtech.h \
    view/supporto/comboboxtrasmissione.h \
    view/supporto/combofilter.h \
    view/supporto/combotype.h \
    view/infolayout.h \
    view/mainlayout.h \
    view/mainwindow.h \
    view/menubartrain.h \
    view/supporto/nievaexception.h \
    view/modificalayout.h \
    view/supporto/trainlist.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    ../../../../../data.json

