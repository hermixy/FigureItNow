#-------------------------------------------------
#
# Project created by QtCreator 2016-01-17T12:55:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FigureItNow7
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    finErrorCode.cpp \
    finFigureObject.cpp \
    finLexNode.cpp \
    finLexReader.cpp \
    finSyntaxNode.cpp \
    finSyntaxReader.cpp \
    finSyntaxOptimzer.cpp \
    finSyntaxTree.cpp \
    finSyntaxError.cpp \
    finExecVariable.cpp \
    finExecFunction.cpp \
    finExecEnvironment.cpp \
    finGraphPanelBase.cpp \
    finGraphPanelQTWidget.cpp \
    finGraphConfig.cpp \
    finFigureContainer.cpp \
    finExecOperartorClac.cpp

HEADERS  += MainWindow.h \
    finErrorCode.h \
    finFigureObject.h \
    finLexNode.h \
    finLexReader.h \
    finSyntaxNode.h \
    finSyntaxReader.h \
    finSyntaxOptimzer.h \
    finSyntaxTree.h \
    finSyntaxError.h \
    finExecVariable.h \
    finExecFunction.h \
    finExecEnvironment.h \
    finGraphPanelBase.h \
    finGraphPanelQTWidget.h \
    finGraphConfig.h \
    finFigureContainer.h \
    finExecOperartorClac.h

FORMS    += MainWindow.ui
