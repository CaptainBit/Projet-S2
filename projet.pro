TEMPLATE = vcapp
TARGET = Tank_war
HEADERS += Vec2.h ./Projectile/Physic.h ./Projectile/Projectile.h ./GameManager/GameManager.h ./GameManager/Joueur.h ./Terrain/Terrain.h ./UI/UI.h ./UI/DosGraph.h Generique.h
SOURCES += main.cpp ./Projectile/Projectile.cpp ./GameManager/GameManager.cpp ./GameManager/Joueur.cpp ./Terrain/Terrain.cpp ./UI/UI.cpp ./UI/DosGraph.cpp Generique.cpp
INCLUDEPATH += ./GameManager
INCLUDEPATH += ./Projectile
INCLUDEPATH += ./UI
INCLUDEPATH += ./Terrain
CONFIG += warn_on qt debug winodws console
QT += widgets
QT += multimedia