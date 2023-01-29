QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bilet.cpp \
    ekranaktywacji.cpp \
    ekranglowny.cpp \
    ekranpodsumowania.cpp \
    ekranreperutar.cpp \
    ekranwyborumiejsc.cpp \
    film.cpp \
    kino.cpp \
    klient.cpp \
    konektorbazydanych.cpp \
    listauzytkownikow.cpp \
    main.cpp \
    mainwindow.cpp \
    menadzeraplikacji.cpp \
    menadzerkin.cpp \
    miejsce.cpp \
    oknoinformacyjne.cpp \
    platnosc.cpp \
    repertuar.cpp \
    sala.cpp \
    seans.cpp

HEADERS += \
    bilet.h \
    ekranaktywacji.h \
    ekranglowny.h \
    ekranpodsumowania.h \
    ekranreperutar.h \
    ekranwyborumiejsc.h \
    film.h \
    kino.h \
    klient.h \
    konektorbazydanych.h \
    listauzytkownikow.h \
    mainwindow.h \
    menadzeraplikacji.h \
    menadzerkin.h \
    miejsce.h \
    oknoinformacyjne.h \
    platnosc.h \
    repertuar.h \
    sala.h \
    seans.h

FORMS += \
    ekranaktywacji.ui \
    ekranglowny.ui \
    ekranpodsumowania.ui \
    ekranreperutar.ui \
    ekranwyborumiejsc.ui \
    mainwindow.ui \
    oknoinformacyjne.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
