#-------------------------------------------------
#
# Project created by QtCreator 2017-07-01T16:47:23
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = portcue
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        src/main.cpp \
        src/ui/mainwindow.cpp \
    src/data/cue.cpp \
    src/data/project.cpp \
    src/io/projectwriter.cpp \
    src/io/projectreader.cpp \
    src/data/audiocue.cpp \
    src/projectmanager.cpp \
    src/ui/projectcreationdialog.cpp \
    src/ui/uihelper.cpp \
    src/ui/maincuetablemodel.cpp \
    src/ui/cuelistwidget.cpp \
    src/ui/cuedatatablemodel.cpp \
    src/ui/editorcuetablemodel.cpp \
    src/ui/editortoolbarwidget.cpp \
    src/ui/projecteditordialog.cpp \
    src/ui/cueeditwidget.cpp \
    src/ui/cuemetawidget.cpp \
    src/ui/cueaudiowidget.cpp

HEADERS += \
        src/ui/mainwindow.h \
    src/data/cue.h \
    src/data/project.h \
    src/io/projectwriter.h \
    src/io/projectreader.h \
    src/io/xmlproperties.h \
    src/data/audiocue.h \
    src/projectmanager.h \
    src/ui/projectcreationdialog.h \
    src/applicationconfig.h \
    src/ui/uihelper.h \
    src/ui/maincuetablemodel.h \
    src/data/irealcue.h \
    src/ui/cuelistwidget.h \
    src/ui/cuedatatablemodel.h \
    src/ui/editorcuetablemodel.h \
    src/ui/editortoolbarwidget.h \
    src/ui/projecteditordialog.h \
    src/ui/cueeditwidget.h \
    src/ui/cuemetawidget.h \
    src/ui/cueaudiowidget.h

FORMS +=

RESOURCES += \
    resources.qrc
