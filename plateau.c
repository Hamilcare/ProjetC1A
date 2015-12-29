#include "plateau.h"
#include "couleur.h"
/*
void init_plateau(Plateau *platal){
	printf("La Debugade\n");
	int i,j;
	for(i=0;i<N;i++){
		for(j=0; j<N; j++){

			if (j>=1 && j<=8){
				platal->pions[i][j] = MAKEBUSHI(0,j,i,0,0);
			}
			else if(j==0 || j==9){
				if(i==4 || i==5){
					platal->pions[i][j] = MAKEBUSHI(0,j,i,0,0);
				}
				else{ 
					platal->pions[i][j] = MAKEBUSHI(-1,j,i,0,0);
				}
			}
			else {
				platal->pions[i][j] = MAKEBUSHI(-1,j,i,0,0);
			}

		}
	}
	platal->pions[1][4] = MAKEBUSHI(-2,1,4,1,0);
	platal->pions[1][5] = MAKEBUSHI(-2,1,5,1,0);
	platal->pions[8][4] = MAKEBUSHI(-2,8,4,2,0);
	platal->pions[8][5] = MAKEBUSHI(-2,8,5,2,0);
}*/

void init_plateaubis(Plateau *plateau)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for(j = 1; j < N - 1; j++)
		{
			plateau->pions[i][j] = EMPTY;
		}	
	}
	for (i = 0; i < N; i++)
	{
		plateau->pions[i][0] = plateau->pions[i][N - 1] = ((i == 4 || i == 5) ? EMPTY : BLOCKED);
	}
}

void affiche_plateau(Plateau *plateau)
{
	int i,j,k;
	char *color;
	
	puts("      ----------------------------------------      ");
	for (i = 0; i < N; i++)
	{
		for (k = 0; k < 2; k++)
		{ 
			for(j = 0; j < N; j++)
			{
	//			affiche_bushi(platal.pions[i][j]);
				if (j == 0 && plateau->pions[i][j].type != -1)
					printf("|");	
				color = ((plateau->pions[i][j].joueur == 1) ? RED : BLUE);
				setcolor(color);	
				switch(plateau->pions[i][j].type)
				{
					case -2 : printf(" PP "); break;
					case -1 : printf("     "); break;
					case 0 : printf("    "); break;
					case 1 : printf(" SS "); break;
					case 2 : printf(" LL "); break;
					case 3 : printf(" DD "); break;
					default : break;
				}
				setcolor(WHITE);
				if (!(j == N - 1 && plateau->pions[i][j].type == -1))
					printf("|");	
			}
			printf("\n");
		}
		if (i >= 3 && i <= 5)
			puts("----------------------------------------------------");
		else
			puts("      ----------------------------------------      ");		
	}
}

void nouvelle_partie(Plateau *plateau){
	FILE* fichier = NULL;
	
	int tmp[5]; //Ce tableau contient la valeur des différents attributs d'un bushi lu depuis pions.txt
				//Dans l'ordre type,abscisse, ordonnee, joueur, alive
	fichier = fopen("standard.txt", "r");
	
	if (fichier != NULL){
		printf("L'ouverture du fichier %s s'est bien déroulée\n","standard.txt");
		while(fscanf(fichier,"%d %d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4])!=EOF){
		
			Bushi test;
			test=MAKEBUSHI(tmp[0],tmp[1], tmp[2], tmp[3], tmp[4]);
			plateau->pions[tmp[2]][tmp[1]]=test;
			//printf("====Bushi===\n");
			//affiche_bushi(test);
		
		}
		
		
		
		
		fclose(fichier);
	}
	
	else {
		printf("Erreur lors de l'ouverture du fichier %s\n","standard.txt");
	}
	
}



//Renvoie la liste des bushis encore en jeu du joueur passé en paramètre
void bushi_joueur(Plateau *plateau, int joueur){
	int i,j;
	int k=0;
	Bushi* tab[NBMAXBUSHIS];
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(plateau->pions[i][j].joueur==joueur && plateau->pions[i][j].type != -2){
				tab[k]=&(plateau->pions[i][j]);
				k++;
			}
		}
	}
	
	
	
	for(i=0;i<k;i++){
		printf("%d. ",i);
		affiche_bushi_coord(tab[i]);
		
	}
	
	
	
}


void deplacement_bushi(Plateau *plateau,Bushi *bushi){
	
	Bushi* moove[DEPLACEMENTSMAX];
	switch(bushi->type){
		case 1 : deplacement_singe(plateau, bushi, moove);break;
		default : break;
	}
}

void deplacement_singe(Plateau *plateau,Bushi *bushi, Bushi* moove[]){
	
	int i,j;
	int k=0;//index du tableau moove

	 
	for(i=1; i>=-1; i--){
		
		for(j=1; j>=-1; j--){
			
			int tempoAbs=bushi->abs+j;
			int tempoOrd=bushi->ord+i;
			
			//on verifie que la case que l'on veut tester est dans le plateau et est valide
			if(est_valide(plateau, *bushi, i,j)==1){
				
				
				//on verifie que la case est vide
				if(plateau->pions[tempoOrd][tempoAbs].type==0){
					moove[k]=&(plateau->pions[tempoOrd][tempoAbs]);
					k++;
					
						
					if(est_valide(plateau, *bushi, 2*i, 2*j)==1){
						tempoAbs+=tempoAbs+j;
						tempoOrd=tempoOrd+i;
					
						//Si la case située à 2 de distance est libre on l'ajoute au déplacment possible
						if(plateau->pions[tempoOrd][tempoAbs].type==0){
						moove[k]=&(plateau->pions[tempoOrd][tempoAbs]);
						k++;
						}
					}

				}
				
			}
		}
	}
					
	
}


int est_valide(Plateau *plateau,Bushi bushi, int x, int y){
	int tempoAbs=bushi.abs+y;
	int tempoOrd=bushi.ord+x;
	int resul=0;
	if(tempoAbs < N && tempoAbs >=0 && tempoOrd < N && tempoOrd >= 0){
		if(plateau->pions[tempoOrd][tempoAbs].type=-1 && plateau->pions[tempoOrd][tempoAbs].type==-2){
			resul=0;
		}
		else{
			resul=1;
		}
	}
	
	printf ("la validité de la case %d %d vaut %d",tempoAbs,tempoOrd,resul);
	return resul;
}



		
	
