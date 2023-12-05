QT       += core gui    \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BulletT.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    MiCaracter.cpp \
    Player.cpp \
    Score.cpp \
    Tower.cpp \
    bala.cpp \
    balaenem.cpp \
    balaesp.cpp \
    bullet.cpp \
    canonbullet.cpp \
    enemigo.cpp \
    main.cpp \
    mainwindow.cpp \
    obstaculo.cpp \
    Button.cpp \
    portal.cpp \
    power.cpp



HEADERS += \
    BulletT.h \
    Enemy.h \
    Game.h \
    GamerOverDialog.h \
    Health.h \
    MiCaracter.h \
    Player.h \
    Score.h \
    Tower.h \
    bala.h \
    balaenem.h \
    balaesp.h \
    bullet.h \
    canonbullet.h \
    enemigo.h \
    mainwindow.h \
    obstaculo.h \
    Button.h    \
    portal.h \
    power.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Recursos.qrc \
    rs.qrc
