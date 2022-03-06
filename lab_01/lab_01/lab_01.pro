QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./src/draw.cpp \
    ./src/errors.cpp \
    ./src/file_io.cpp \
    ./src/line.cpp \
    ./src/main.cpp \
    ./src/mainwindow.cpp \
    ./src/matrix.cpp \
    ./src/model.cpp \
    ./src/point.cpp \
    ./src/projection.cpp

HEADERS += \
    ./inc/draw.h \
    ./inc/errors.h \
    ./inc/file_io.h \
    ./inc/line.h \
    ./inc/mainwindow.h \
    ./inc/matrix.h \
    ./inc/model.h \
    ./inc/point.h \
    ./inc/projection.h

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
