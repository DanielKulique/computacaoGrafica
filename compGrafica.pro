QT       += core gui widgets

CONFIG   += c++17

TARGET   = compGrafica
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    areadesenho.cpp \
    Objeto.cpp \
    Ponto.cpp \
    Reta.cpp \
    ObjetoPonto.cpp \
    Poligono.cpp

HEADERS += \
    mainwindow.h \
    areadesenho.h \
    Objeto.h \
    Ponto.h \
    Reta.h \
    ObjetoPonto.h \
    Poligono.h \
    DisplayFile.h

FORMS += \
    mainwindow.ui
