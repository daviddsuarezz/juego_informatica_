QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Bullet.cpp \
    Enemy.cpp \
    Game.cpp \
    Tower.cpp \
    character.cpp \
    enemybullet.cpp \
    enemyshoots.cpp \
    main.cpp \
    mainwindow.cpp \
    obstacle.cpp \
    obstacle2.cpp

HEADERS += \
    Bullet.h \
    Enemy.h \
    Game.h \
    Tower.h \
    Ui_level1.h \
    character.h \
    enemybullet.h \
    enemyshoots.h \
    mainwindow.h \
    obstacle.h \
    obstacle2.h

FORMS += \
    level1.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
