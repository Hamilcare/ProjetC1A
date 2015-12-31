#include "bushi.h"



void affiche_bushi(Bushi b){


	printf("type : %d\n",b.type);
	printf("joueur : %d\n",b.joueur);
	printf("jouable : %d\n",b.jouable);
	printf("abcisse : %d\n",b.abs);
	printf("ordonnee : %d\n",b.ord);
	

}

void affiche_bushi_coord(Bushi *b){
 
    char *type;
 
    switch(b->type)
    {
        case 1 : type = "SNG"; break;
        case 2 : type = "LIO"; break;
        case 3 : type = "DRA"; break;
        case -2 : type = "POR"; break;
        case 0 : type ="DEP"; break;
        case -1 : type = "BLO";break;
        default : type="BIDE";break;
    }
    printf("[%s] (%c,%d)    ",type,b->abs + 'A',b->ord);
    //printf("Type de deplacment : %d ",b->jouable);
}
