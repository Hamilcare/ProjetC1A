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
   
}

/*
 * Bushi bushi -> le bushi qu'on cherche dans tab
 * Bushi* tab -> Le tableau dans lequel on cherce
 * int k-> Le nombre d'éléments dans tab
 * 
 * Return la position du Bushi dans le tableau si il est présent
 * Return -1 si il est absent*/ 
int est_dans(Bushi bushi, Bushi* tab, int k){
	//printf("coucou\n");
	int resul=-1;
	int compteur=0;
	while(compteur < k && resul==-1){
		if(bushi.abs == tab[compteur].abs && bushi.ord==tab[compteur].ord){
			resul=compteur;
		}
		compteur++;
	}
	if(resul !=-1){
		//printf("%d\n",resul);
	}
	return resul;
}
