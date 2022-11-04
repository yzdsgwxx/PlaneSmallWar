QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
QT+=multimedia
SOURCES += \
    Plane.cpp \
    bullet.cpp \
    bulletBlue.cpp \
    bulletred.cpp \
    enemy.cpp \
    enemy1.cpp \
    enemy2.cpp \
    flyer.cpp \
    heroplane.cpp \
    heroplane1.cpp \
    losemenu.cpp \
    main.cpp \
    mainscene.cpp \
    map.cpp \
    movevector.cpp \
    pausescene.cpp \
    startmenu.cpp \
    supply.cpp \
    supplyinvincible.cpp

HEADERS += \
    Plane.h \
    bullet.h \
    bulletBlue.h \
    bulletred.h \
    config.h \
    enemy.h \
    enemy1.h \
    enemy2.h \
    flyer.h \
    heroplane.h \
    heroplane1.h \
    losemenu.h \
    mainscene.h \
    map.h \
    movevector.h \
    pausescene.h \
    startmenu.h \
    supply.h \
    supplyinvincible.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


FORMS += \
    losemenu.ui \
    mainscene.ui \
    pausescene.ui \
    startmenu.ui

RESOURCES += \
    res.qrc







