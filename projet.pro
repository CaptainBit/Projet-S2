TEMPLATE = vcapp
TARGET = Tank_war
HEADERS += Interface.h Tank.h Vec2.h ./Projectile/Physic.h ./Projectile/Projectile.h ./GameManager/GameManager.h ./GameManager/Joueur.h ./Terrain/Terrain.h ./Terrain/Generique.h
SOURCES += Interface.cpp Tank.cpp main.cpp ./Projectile/Projectile.cpp ./GameManager/GameManager.cpp ./GameManager/Joueur.cpp ./Terrain/Terrain.cpp ./Terrain/Generique.cpp
INCLUDEPATH += ./GameManager
INCLUDEPATH += ./Projectile
INCLUDEPATH += ./Terrain
CONFIG += warn_on qt debug winodws console
QT += widgets