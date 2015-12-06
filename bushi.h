#ifndef BUSHI_H
	#define BUSHI_H

	#define         MAKEBUSHI(type, abs, ord, joueur)   ((Bushi){type, abs, ord, joueur})               

typedef struct Bushi Bushi;
struct Bushi {
	int type; // 1=Singe, 2=Lion, 3= Dragon	
	int abs; // Cellule du Bushi	
	int ord;
	int joueur; // Joueur à qui appartient le bushi 	
	int alive; // 1 = En vie, 0= Hors-jeu
};









void affiche_bushi(Bushi b);

void charger_partie(const char* fileName, Bushi pions[M]);

#endif
