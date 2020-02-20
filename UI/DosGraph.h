#pragma once
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

/*----------------------------------------------
Enumération des différentes couleurs disponibles
------------------------------------------------*/
enum COLORS {
	NOIR = 0,
	BLEU = FOREGROUND_BLUE,
	VERT = FOREGROUND_GREEN,
	CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
	ROUGE = FOREGROUND_RED,
	MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
	BRUN = FOREGROUND_RED | FOREGROUND_GREEN,
	GRIS = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	GRIS_CLAIR = FOREGROUND_INTENSITY,
	BLEU_CLAIR = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	VERT_CLAIR = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	CYAN_CLAIR = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	ROUGE_CLAIR = FOREGROUND_RED | FOREGROUND_INTENSITY,
	MAGENTA_CLAIR = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	JAUNE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	BLANC = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
};

// Caractères spéciaux
extern char CaractereSmiley1;
extern char CaractereSmiley2;
extern char CaractereCoeur;
extern char CaractereCarreau;
extern char CaractereTrefle;
extern char CaracterePique;
extern char CaractereCercle;
extern char CaractereSymboleHomme;
extern char CaractereSymboleFemme;
extern char CaractereCroche;
extern char CaractereCrocheLiee;
extern char CaractereSoleil;
extern char CaractereFleches1;
extern char CaractereFlecheHaut;
extern char CaractereFlecheBas;
extern char CaractereFlecheDroite;
extern char CaractereFlecheGauche;
extern char CaractereAngle;
extern char CaractereFleches2;

// > 128 (unsigned)
extern unsigned char CaractereBoite1;
extern unsigned char CaractereBoite2;
extern unsigned char CaractereBoite3;

// Caractères pour dessiner un cadre
struct CadreStyle {
  unsigned char cBordureV;
  unsigned char cBordureH;
  unsigned char cBordureSupGauche;
  unsigned char cBordureSupDroite;
  unsigned char cBordureInfGauche;
  unsigned char cBordureInfDroite;
};
// Caractères de bordures
// Cadre à un trait
const CadreStyle CadreSimple = {
  179, 196, 218, 191, 192, 217
};

// Cadre à double traits
const CadreStyle CadreDouble = {
  186, 205, 201, 187, 200, 188
};
// Cadre à double traits horizontal
const CadreStyle CadreDoubleH = {
  179, 205, 213, 284, 212, 290
};
// Cadre à double traits vertical
const CadreStyle CadreDoubleV;

// Structure qui sauvegarde la position du curseur à la construction
// puis remet la position initiale lors de la destruction de l'objet.
struct SauvgCurseurPosition
{
  SauvgCurseurPosition();
  ~SauvgCurseurPosition();
private:
  int x, y;
};

struct SauvgColorationTexte
{
  SauvgColorationTexte();
  ~SauvgColorationTexte();
private:
  COLORS couleur_texte;
  COLORS couleur_fond;
};

// Dessine un cadre à l'aide des caractères spéciaux
// @paramètre int x1 Abscisse, en caractère, du point de départ (coin supérieur gauche)
// @paramètre int y1 Ordonnée, en caractère, du point de départ (coin supérieur gauche)
// @paramètre int x2 Abscisse, en caractère, du point d'arrivée (coin inférieur droit)
// @paramètre int y2 Ordonnée, en caractère, du point d'arrivée (coin inférieur droit)
// @paramètre Cadre style Choix des symboles pour dessiner le cadre
// @paramètre bool efface Efface l'intérieur du cadre à l'aide de caractères vides.
void dessinerCadre(int x1, int y1, int x2, int y2, const CadreStyle& style = CadreSimple, bool efface = false);

/******************************************************************
Vider l'ecran de son contenu.
******************************************************************/
void clearScreen();

/******************************************************************
Changer la couleur du texte a etre insere.
@param newcolor : la nouvelle couleur, telle que decrite dans COLORS.
@exemple : textColor( NOIR );
******************************************************************/
void setTextColor(int newColor);

/******************************************************************
Changer la couleur de fond du texte a etre insere.
@param newcolor : la nouvelle couleur, telle que decrite dans COLORS.
@exemple : textBackground( BLACK );
******************************************************************/
void setBackgroundColor(int newColor);

/******************************************************************
Changer la couleur du texte et du fond du texte a etre insere.
@param newcolor : la nouvelle couleur, telle que decrite dans COLORS.
@exemple : textBackground( NOIR );
******************************************************************/
void setTextBackgroundColor(int newColorText, int newColorBack);

/******************************************************************
Obtenir la couleur du texte et du fond du texte.
@param newColorText : la couleur du texte, telle que decrite dans COLORS.
@param newColorBack : la couleur du fond
@exemple : 
******************************************************************/
//void getTextBackgroundColor(COLORS& newColorText, COLORS& newColorBack);

/******************************************************************
Changer la position du curseur.
@param x : le numero de colonne.
@param y : le numero de ligne.
@pre-conditions : (x,y) doit etre un point dans l'ecran.
******************************************************************/
void setXY(int x, int y);

/******************************************************************
Changer le curseur de colonne.
@param x : le numero de colonne.
@pre-conditions : x doit etre une colonne dans l'ecran.
******************************************************************/
void setX(int x);

/******************************************************************
Changer le curseur de ligne.
@param y : le numero de ligne.
@pre-conditions : y doit etre une ligne dans l'ecran.
******************************************************************/
void setY(int y);

/******************************************************************
Obtenir la colonne du curseur.
@retourne : le numero de colonne.
******************************************************************/
int getX();

/******************************************************************
Obtenir la ligne du curseur.
@retourne : le numero de ligne.
******************************************************************/
int getY();

/******************************************************************
Obtenir la ligne et la colonne du curseur.
@param x : le numero de colonne.
@param y : le numero de ligne.
******************************************************************/
void getXY(int& x, int&y);

/******************************************************************
Obtenir la ligne du curseur.
@retourne : le numero de ligne.
******************************************************************/
int getY();
/******************************************************************
Specifie les dimensions de l'ecran.
@param x : le nombre de colonnes.
@param y : le nombre de lignes.
******************************************************************/
void setScreen(int x, int y);

/******************************************************************
Specifie le titre de la fenetre.
@param titre : chaine de caracteres contenant le nouveau titre.
******************************************************************/
void setTitre(char titre[]);

/******************************************************************
Affiche ou cache le curseur dans l'ecran.
@param mode : si VRAI, affiche le curseur. Si FAUX, le cache.
******************************************************************/
void showCursor(bool mode);

/******************************************************************
Maximise la fenetre a l'ecran.
******************************************************************/
void maximise();

/******************************************************************
Specifie les dimensions de l'ecran.
@param x : sortie : le nombre de colonnes.
@param y : sortie : le nombre de lignes.
******************************************************************/
void getScreen(int & x, int & y);

/******************************************************************
Obtient le caractere a l'ecran a la position (x,y)
@param x : le numero de colonne.
@param y : le numero de ligne.
@retourne : la charactere qui est affiche a l'ecran.
******************************************************************/
char getCharAt(int x, int y);
void setEntete(string Titre);