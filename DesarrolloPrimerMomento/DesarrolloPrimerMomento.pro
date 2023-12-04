QT       += core gui    \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GlobalVariable.cpp \
    MiCaracter.cpp \
    bala.cpp \
    balaenem.cpp \
    balaesp.cpp \
    enemigo.cpp \
    main.cpp \
    mainwindow.cpp \
    obstaculo.cpp \
    Button.cpp \



HEADERS += \
    GlobalVariable.h \
    MiCaracter.h \
    bala.h \
    balaenem.h \
    balaesp.h \
    enemigo.h \
    mainwindow.h \
    obstaculo.h \
    Button.h    \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc \
    rs.qrc
