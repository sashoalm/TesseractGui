#-------------------------------------------------
#
# Project created by QtCreator 2016-07-03T21:30:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TesseractGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    widget.cpp \
    thread.cpp

HEADERS  += mainwindow.h \
    widget.h \
    thread.h

FORMS    += mainwindow.ui

unix: {
    LIBS += -L/usr/local/lib -ltesseract -llept
}

DISTFILES += \
    README.txt

win32: {
    DEFINES += WINDOWS
    DESTDIR = ./win
    OBJECTS_DIR += temp
    MOC_DIR     += temp
    UI_DIR      += temp
    RCC_DIR     += temp
    INCLUDEPATH += f:/win64/include/
    LIBS += -lws2_32 -Lf:/win64/lib/
    CONFIG(debug, debug|release) {
        TARGET = $$join(TARGET,,,d)
        LIBS += -ltesseract40d -lpvt.cppan.demo.danbloomberg.leptonica-1.76.0
    } else {
        LIBS += -ltesseract40 -lpvt.cppan.demo.danbloomberg.leptonica-1.76.0
    }
}
