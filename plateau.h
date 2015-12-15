#ifndef PLATEAU_H
	#define PLATEAU_H
	#include "include.h"
	#include "bushi.h"

typedef struct Plateau Plateau;
struct Plateau{
	Bushi pions [N][N];
};

extern Plateau plateau;

void init_plateau(Plateau *plateau);
void init_plateaubis(Plateau *plateau);
void affiche_plateau(Plateau *plateau);
void nouvelle_partie(Plateau *plateau);
#endif
