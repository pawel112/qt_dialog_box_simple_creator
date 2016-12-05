#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T15:26:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dialog_box_simple_creator
TEMPLATE = app


SOURCES += main.cpp\
        main_window.cpp \
    settings.cpp \
    create_files.cpp \
    language.cpp \
    done_window.cpp \
    error.cpp \
    new_int.cpp \
    new_float.cpp \
    new_string.cpp \
    new_no_validation.cpp \
    aboutwindow.cpp

HEADERS  += main_window.h \
    settings.h \
    create_files.h \
    language.h \
    done_window.h \
    error.h \
    new_int.h \
    new_float.h \
    new_string.h \
    new_no_validation.h \
    structure.h \
    aboutwindow.h

FORMS    += main_window.ui \
    done_window.ui \
    error_window.ui \
    new_int_window.ui \
    new_float_window.ui \
    new_string_window.ui \
    new_no_validation_window.ui \
    about_window.ui
