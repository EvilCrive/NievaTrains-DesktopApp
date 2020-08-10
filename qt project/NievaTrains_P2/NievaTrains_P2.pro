QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

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
    view/mainwindow.cpp \
    view/view.cpp

HEADERS += \
    Qontainer.h \
    model/model.h \
    model/gerarchia/bimode.h \
    model/gerarchia/electric.h \
    model/gerarchia/internal_combustion.h \
    model/gerarchia/maglev.h \
    model/gerarchia/steam.h \
    model/gerarchia/treno.h \
    view/mainwindow.h \
    view/view.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

