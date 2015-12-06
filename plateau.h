#ifndef PLATEAU_H
	#define PLATEAU_H
	#include "include.h"
	#include "bushi.h"

typedef struct Plateau Plateau;
struct Plateau{
	Bushi pions [N][N];
};

void init_plateau(Plateau platal);
void affiche_plateau(Plateau platal);
#endif
