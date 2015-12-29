#ifndef BUSHI_H
	#define BUSHI_H
	#include "include.h"
	#define         MAKEBUSHI(type, abs, ord, joueur, alive) ((Bushi){type, abs, ord, joueur, alive})               
	#define		EMPTY					 MAKEBUSHI(0, 0, 0, 0, 0)
	#define 	BLOCKED					 MAKEBUSHI(-1, 0, 0, 0, 0)

typedef struct Bushi Bushi;
struct Bushi {
	int type; // 1=Singe, 2=Lion, 3= Dragon	-1=blocked 0=empty -2=portal
	int abs; // Cellule du Bushi	
	int ord;
	int joueur; // Joueur à qui appartient le bushi 	
	int alive; // 1 = En vie, 0= Hors-jeu
};









void affiche_bushi(Bushi b);
void affiche_bushi_coord(Bushi *b);

//void charger_partie(const char* fileName, Bushi pions[N]);

#endif
