#include "bushi.h"



void affiche_bushi(Bushi b){


	printf("type : %d\n",b.type);
	printf("joueur : %d\n",b.joueur);
	printf("jouable : %d\n",b.jouable);
	printf("abcisse : %d\n",b.abs);
	printf("ordonnee : %d\n",b.ord);
	

}

void affiche_bushi_coord(Bushi *b){
	printf("Type %d : (%c,%d)	",b->type,b->abs + 'A',b->ord);
	//printf("Type de deplacment : %d ",b->jouable);
}

