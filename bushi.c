#include "bushi.h"



void affiche_bushi(Bushi b){


	printf("type : %d\n",b.type);
	printf("joueur : %d\n",b.joueur);
	printf("alive : %d\n",b.alive);
	printf("abcisse : %d\n",b.abs);
	printf("ordonnee : %d\n",b.ord);
	

}

void affiche_bushi_coord(Bushi *b){
	printf("Type %d : (%d,%d)\n",b->type,b->abs,b->ord);
}


	
	
				
	
	




/* Charge une partie à partir des données fournies dans le 
 * fichier fileName
void charger_partie(const char* fileName, Bushi pions[N]){
	FILE* fichier = NULL;
	int tmp[5]; //Ce tableau contient la valeur des différents attributs d'un bushi lu depuis pions.txt
				//Dans l'ordre joueur, type, abscisse, ordonnee, alive
	fichier = fopen(fileName, "r");
	
	if (fichier != NULL){
		printf("L'ouverture du fichier %s s'est bien déroulée\n",fileName);
		while(fscanf(fichier,"%d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3])!=EOF){
		
			Bushi test;
			test=MAKEBUSHI(tmp[0],tmp[2], [tmp[3]], tmp[1]);//crée un bushi à l'aide de la macro WALLAH
			printf("====Bushi===\n");
			affiche_bushi(test);
		
		}
		
		
		
		
		fclose(fichier);
	}
	
	else {
		printf("Erreur lors de l'ouverture du fichier %s\n",fileName);
	}
	
}
*/

