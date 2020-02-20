#include "DosGraph.h"

#define STDOUT GetStdHandle(STD_OUTPUT_HANDLE)

static WORD bgcolor = NOIR;
static WORD fgcolor = BLANC  << 4;
static HWND console = 0;
static HDC dc = 0;
// Caractère spéciaux
char CaractereSmiley1 = 1;
char CaractereSmiley2 = 2;
char CaractereCoeur = 3;
char CaractereCarreau = 4;
char CaractereTrefle = 5;
char CaracterePique = 6;
char CaractereCercle = 7;
char CaractereSymboleHomme = 11;
char CaractereSymboleFemme = 12;
char CaractereCroche = 13;
char CaractereCrocheLiee = 14;
char CaractereSoleil = 15;
char CaractereFleches1 = 18;
char CaractereFlecheHaut = 24;
char CaractereFlecheBas = 25;
char CaractereFlecheDroite = 26;
char CaractereFlecheGauche = 27;
char CaractereAngle = 28;
char CaractereFleches2 = 29;



// > 128 (unsigned)
unsigned char CaractereBoite1 = 176;
unsigned char CaractereBoite2 = 177;
unsigned char CaractereBoite3 = 178;

extern const CadreStyle CadreSimple;  // Cadre à un trait
extern const CadreStyle CadreDouble;  // Cadre à double traits

//-----------------------------------------------------
void dessinerCadre(int x1, int y1, int x2, int y2, const CadreStyle& style, bool efface)
{
  SauvgCurseurPosition sauv_curseur;

  setXY(x1, y1);
  cout << style.cBordureSupGauche;
  for (int x = x1 + 1; x < x2; x++)
  {
    cout << style.cBordureH;
  }
  cout << style.cBordureSupDroite;
  for (int y = y1 + 1; y < y2; y++)
  {
    setXY(x2, y);
    cout << style.cBordureV;
  }
  setXY(x2, y2);
  cout << style.cBordureInfDroite;

  setXY(x1, y2);
  cout << style.cBordureInfGauche;
  for (int x = x1 + 1; x < x2; x++)
  {
    cout << style.cBordureH;
  }
  for (int y = y1 + 1; y < y2; y++)
  {
    setXY(x1, y);
    cout << style.cBordureV;
  }
  x1 = 0, x2 = 0, y1 = 0, y2 = 0;
}

//-----------------------------------------------------
int getX( void ) 
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo (STDOUT, &coninfo);
	return coninfo.dwCursorPosition.X;
}

//-----------------------------------------------------
int getY( void ) 
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo (STDOUT, &coninfo);
	return coninfo.dwCursorPosition.Y;
}
//-----------------------------------------------------
void getXY(int& x, int&y)
{
	x = getX();
	y = getY();
}
//-----------------------------------------------------
void setXY( int x, int y ) 
{
	COORD dwCursorPosition = { x, y };
	SetConsoleCursorPosition (STDOUT, dwCursorPosition);
}

//-----------------------------------------------------
void setX (int x)
{
	int y = getY();
	COORD dwCursorPosition = { x, y };
	SetConsoleCursorPosition (STDOUT, dwCursorPosition);
}

//-----------------------------------------------------
void setY (int y)
{
	int x = getX();
	COORD dwCursorPosition = { x, y };
	SetConsoleCursorPosition (STDOUT, dwCursorPosition);
}

//-----------------------------------------------------
void setTextColor( int newColor )
{
	bgcolor = newColor;
	SetConsoleTextAttribute (STDOUT, fgcolor | bgcolor);
}

//-----------------------------------------------------
void setBackgroundColor( int newColor )
{
	fgcolor = newColor << 4;
	SetConsoleTextAttribute (STDOUT, fgcolor | bgcolor);
}

//-----------------------------------------------------
void setTextBackgroundColor( int newColorText, int newColorBack )
{
	setTextColor(newColorText);
	setBackgroundColor(newColorBack);
}


//void getTextBackgroundColor(COLORS& couleur_texte, COLORS& couleur_fond)
//{
//  couleur_texte = bgcolor;
//  couleur_fond = fgcolor;
//}
//-----------------------------------------------------
void clearScreen( void )
{
	HANDLE hstdout = STDOUT;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo (hstdout, &csbi))
	{
		COORD coordScreen = { 0, 0 };
		DWORD cCharsWritten;
		DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
		FillConsoleOutputCharacter (hstdout, ' ', dwConSize, coordScreen, &cCharsWritten);
		FillConsoleOutputAttribute (hstdout, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
		SetConsoleCursorPosition    (hstdout, coordScreen);
	}
}

//-----------------------------------------------------
void setScreen(int x, int y)
{	
	COORD coordScreen = { x, y };
	SMALL_RECT rect = {0, 0, x-1, y-1 };
	
	SetConsoleScreenBufferSize(STDOUT, coordScreen);
	SetConsoleWindowInfo(STDOUT, TRUE, &rect);
}

//-----------------------------------------------------
void maximise( void )
{
	SMALL_RECT rect = {0, 0, 0, 0};
	COORD coord;

	coord = GetLargestConsoleWindowSize(STDOUT);
    
	SetConsoleScreenBufferSize(STDOUT, coord);
	
	rect.Right = coord.X - 30;
   rect.Bottom = coord.Y - 15;

    SetConsoleWindowInfo(STDOUT, TRUE, &rect);

}

//-----------------------------------------------------
void setTitre(char titre[])
{
	SetConsoleTitleA(titre);
}

//-----------------------------------------------------
void showCursor(bool mode)
{
	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(STDOUT, &cursor);

	if (mode == TRUE)
		cursor.bVisible = TRUE;
	else
		cursor.bVisible = FALSE;
	
	SetConsoleCursorInfo(STDOUT, &cursor);
}

//-----------------------------------------------------
void getScreen(int & x, int & y)
{
	CONSOLE_SCREEN_BUFFER_INFO info;

	GetConsoleScreenBufferInfo(STDOUT, &info);
	x = info.srWindow.Right+1;
	y = info.srWindow.Bottom+1;
}
//-----------------------------------------------------
char getCharAt(int x, int y)
{
	CHAR_INFO pci;
	
	COORD coord;
	coord.X = 1;
	coord.Y = 1;

	int width, height;
	getScreen(width,height);

	COORD pos;

	pos.X = 0;
	pos.Y = 0;

	SMALL_RECT rec;

	rec.Left = x;
	rec.Right = x;
	rec.Top = y;
	rec.Bottom = y;

	ReadConsoleOutput(STDOUT, & pci, coord, pos, & rec);

	return pci.Char.AsciiChar;
}
//-----------------------------------------------------
SauvgColorationTexte::SauvgColorationTexte()
{
  setTextBackgroundColor(couleur_texte, couleur_fond);
}

SauvgColorationTexte::~SauvgColorationTexte()
{
 // getTextBackgroundColor(couleur_texte, couleur_fond);
}

SauvgCurseurPosition::SauvgCurseurPosition()
{
  // Sauvgarde la position du curseur
  // afin de la restaurer lors de la
  // destruction de l'objet.
  getXY(x, y);
}

SauvgCurseurPosition::~SauvgCurseurPosition()
{
  // Déplace le curseur là ou il était lors de
  // la construction de l'objet.
  setXY(x, y);
}
double SizeTitre = 0;
void setEntete(string Titre){
	cout << "     " << Titre << "     " << endl;
	SizeTitre = sizeof(Titre);
	cout << endl << SizeTitre;

	dessinerCadre(0, getY(), SizeTitre, getY(), CadreSimple, false);
	SizeTitre = 0;
	cout.clear();
	cin.clear();
}