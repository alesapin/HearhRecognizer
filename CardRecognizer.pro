#-------------------------------------------------
#
# Project created by QtCreator 2015-08-07T14:06:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11 console



TARGET = CardRecognizer
TEMPLATE = app


SOURCES += main.cpp\
        Main.cpp \
    util.cpp

HEADERS  += Main.h \
    util.h
include(extractor/extractor.pri)
include(cards/cards.pri)
include(dbconnector/dbconnector.pri)
include(screencontroller/screencontroller.pri)

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_text
LIBS +=`pkg-config opencv --cflags --libs`
LIBS += -ltesseract -llept -pthread -lmongoclient -lboost_thread -lboost_system -lboost_regex
