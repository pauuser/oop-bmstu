QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    draw.cpp \
    errors.cpp \
    file_io.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    matrix.cpp \
    model.cpp \
    point.cpp \
    projection.cpp

HEADERS += \
    draw.h \
    errors.h \
    file_io.h \
    line.h \
    mainwindow.h \
    matrix.h \
    model.h \
    point.h \
    projection.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    lab_01_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    test.txt
