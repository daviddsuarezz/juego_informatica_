QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    BulletT.cpp \
    Button.cpp \
    Enemy.cpp \
    Game.cpp \
    Health.cpp \
    Player.cpp \
    Score.cpp \
    Tower.cpp \
    canonbullet.cpp \
    main.cpp \
    mainwindow.cpp \
    portal.cpp \
    power.cpp

HEADERS += \
    Bullet.h \
    BulletT.h \
    Button.h \
    Enemy.h \
    Game.h \
    GamerOverDialog.h \
    Health.h \
    Player.h \
    Score.h \
    Tower.h \
    canonbullet.h \
    mainwindow.h \
    portal.h \
    power.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rs.qrc

