/*
Structure de coordonnées de l'application
*/

#ifndef PROJET_COORD_H
#define PROJET_COORD_H
struct Vec2{
    int x;
    int y;

    Vec2(int p_x = 0.0f, int p_y = 0.0f){
        x = p_x;
        y = p_y;
    }
};

#endif //PROJET_COORD_H
