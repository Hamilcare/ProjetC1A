#include "plateau.h"
#include "couleur.h"

void empty_buffer()
{

    char c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

void init_plateaubis(Plateau *plateau)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for(j = 1; j < N - 1; j++)
		{
			plateau->pions[i][j] = EMPTY(i,j);
		}	
	}
	for (i = 0; i < N; i++)
	{
		plateau->pions[i][0] = plateau->pions[i][N - 1] = ((i == 4 || i == 5) ? EMPTY(i,j) : BLOCKED);
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





//Place les bushis spécifiés dans le fichier txt selectionné
void nouvelle_partie(Plateau *plateau){
	int choix;
	FILE* fichier = NULL;
	
	do{
		printf("\nQuel type de partie souhaitez vous lancer?\n");
		printf("1.Partie standard\n");
		printf("2.Situation ShingShang\n");
		scanf("%d",&choix);
		empty_buffer();
	}while(choix <=0 || choix >2);
	
	switch (choix){
		case 1: fichier = fopen("standard.txt", "r"); break;
		case 2: fichier = fopen("shingshang.txt", "r");break;
		default: break;
	}
	
	
				
	
	
	
	if (fichier != NULL){
		
		printf("L'ouverture du fichier s'est bien déroulée\n");
		int tmp[5]; //Ce tableau contient la valeur des différents attributs d'un bushi lu depuis pions.txt
					//Dans l'ordre type,abscisse, ordonnee, joueur, alive
					
		while(fscanf(fichier,"%d %d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4])!=EOF){
		
			Bushi test;
			test=MAKEBUSHI(tmp[0],tmp[1], tmp[2], tmp[3], tmp[4]);
			plateau->pions[tmp[2]][tmp[1]]=test;
			
		
		}
		
		
		
		
		fclose(fichier);
	}
	
	else {
		printf("Erreur lors de l'ouverture du fichier \n");
	}
	
}



//Renvoie la liste des bushis encore en jeu du joueur passé en paramètre
Bushi* bushi_joueur(Plateau *plateau, int joueur)
{
	int i,j;
	int k=0;
	int choix = -1;
	Bushi* tab[NBMAXBUSHIS];
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(plateau->pions[i][j].joueur==joueur && plateau->pions[i][j].type != -2 && plateau->pions[i][j].jouable==1){
				tab[k]=&(plateau->pions[i][j]);
				printf("Adresse des cases du tableau : %p \n",&(plateau->pions[i][j]));
				//printf("Bushi ajoute\n");
				k++;
				//printf("Valeur de k : %d\n",k);
			}
		}
	}
	
	
	printf("Liste des bushis que vous pouvez jouer : %d différents \n",k);
	for(i=0;i<k;i++){
		printf("%d. ",i+1);
		affiche_bushi_coord(tab[i]);
		if((i+1)%6==0){
			printf("\n");
		}
		
	}
	
	
	
	while(choix<=0 || choix>k){
		printf("\nSelectionnez le bushi que vous souhaitez déplacer\n");
		scanf("%d",&choix);
		empty_buffer();
	}
	printf("Adresse du pointeur renvoyé : %p\n",tab[choix-1]);
	return tab[choix-1];
	
}







Bushi deplacement_bushi(Plateau *plateau,Bushi *bushi)
{
	int i,k;
	int choix=-1;
	Bushi moove[DEPLACEMENTSMAX];
	switch(bushi->type){
		case 1 : k=deplacement_singe(plateau, bushi, moove);break;
		default : break;
	}
	
	
	for(i=0; i<k; i++){
		printf("%d. ",i+1);
		affiche_bushi_coord(&(moove[i]));
		printf("Type dep : %d\n",(moove[i].jouable));
		if((i+1)%6==0){
			printf("\n");
		}
		
	}
	printf("%d. Changer de Bushi\n",k+1);
	
	
	while(choix<=0 || choix>k+1){
		printf("\nSelectionnez votre case d'arrivée\n");
		scanf("%d",&choix);
		empty_buffer();
	}
	
	if(choix==k+1){
		return EMPTY(0,0);
	}
	else{
		printf("Destination in deplacement_bushi\n");
		affiche_bushi(moove[choix-1]);
		return moove[choix-1];
	}
		
}

void affiche_bis(Plateau *plateau){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d",plateau->pions[i][j].type);
		}
		printf("\n");
	}
}

/*
//return la taille de moove
int deplacement_singe(Plateau *plateau,Bushi *bushi, Bushi moove[])
{
	
	int i,j;
	int k=0;//index du tableau moove

	 
	for(i=1; i>=-1; i--){
		
		for(j=1; j>=-1; j--){
			
			int tempoAbs=(bushi->abs)+j;
			int tempoOrd=(bushi->ord)+i;
			
			//on verifie que la case que l'on veut tester est dans le plateau et est valide
			if(est_valide(plateau, *bushi, i,j)==1){
				
				
				//on verifie que la case est vide
				if(plateau->pions[tempoOrd][tempoAbs].type==0){
					moove[k]=(plateau->pions[tempoOrd][tempoAbs]);
					k++;
					//printf("--La case (%d,%d) est de type %d --\n",tempoAbs,tempoOrd,plateau->pions[tempoOrd][tempoAbs].type);
					//printf("---La case (%d,%d) est ajoutee aux deplacements---\n",tempoAbs,tempoOrd);
					
						
					if(est_valide(plateau, *bushi, 2*i, 2*j)==1){
						tempoAbs=tempoAbs+j;
						tempoOrd=tempoOrd+i;
					
						//Si la case située à 2 de distance est libre on l'ajoute au déplacment possible
						if(plateau->pions[tempoOrd][tempoAbs].type==0){
							//printf("YOLO\n");
							moove[k]=(plateau->pions[tempoOrd][tempoAbs]);
							//affiche_bushi(plateau->pions[tempoOrd][tempoAbs]);
							k++;
							//printf("--La case (%d,%d) est de type %d --\n",tempoAbs,tempoOrd,plateau->pions[tempoOrd][tempoAbs].type);
							//printf("---La case (%d,%d) est ajoutee aux deplacements---\n",tempoAbs,tempoOrd);
						}
					}

				}
				
				else if (plateau->pions[tempoOrd][tempoAbs].type==1){
					
					if(est_valide(plateau, *bushi, 2*i, 2*j)==1){
						tempoAbs=tempoAbs+j;
						tempoOrd=tempoOrd+i;
					
						//Si la case située à 2 de distance est libre on l'ajoute au déplacment possible
						if(plateau->pions[tempoOrd][tempoAbs].type==0){
							//printf("YOLO\n");
							moove[k]=(plateau->pions[tempoOrd][tempoAbs]);
							affiche_bushi(plateau->pions[tempoOrd][tempoAbs]);
							k++;
							//printf("--La case (%d,%d) est de type %d --\n",tempoAbs,tempoOrd,plateau->pions[tempoOrd][tempoAbs].type);
							//printf("---La case (%d,%d) est ajoutee aux deplacements---\n",tempoAbs,tempoOrd);
						}
					}
					
					
				}
					
				
			}
		}
	}
	
	for(i=0; i<k; i++){
		printf("%d. ",i+1);
		affiche_bushi(moove[i]);
		
	}
	
	return k;			
	
}*/


int deplacement_singe(Plateau *plateau,Bushi *bushi, Bushi moove[])
{
	
	int i,j;
	int k=0;//index du tableau moove
	int valide=0;
	int tempoAbs=0;
	int tempoOrd=0;
	int aSaute=0;//0 pas de saut / -1 saut d'un ennemi / 1 saut d'un allie

	 
	for(i=1; i>=-1; i--){
		
		for(j=1; j>=-1; j--){
			
			valide=est_valide(plateau,*bushi,i,j);
			
			switch(valide) {
			
			//La case est vide
			case 0 :
				tempoAbs=(bushi->abs)+j;
				tempoOrd=(bushi->ord)+i;
				moove[k]=(plateau->pions[tempoOrd][tempoAbs]);
				k++;
				//On teste la case un coup plus loin dans l'alignement
				valide=est_valide(plateau, *bushi, 2*i, 2*j);
				
				if(valide==0){
					tempoAbs=tempoAbs+j;
					tempoOrd=tempoOrd+i;
					moove[k]=(plateau->pions[tempoOrd][tempoAbs]);
					k++;
				}
				break;
			
			
			case 1 :
				
					
				valide=est_valide(plateau, *bushi, 2*i, 2*j);
				if(valide==0){
					if(plateau->pions[tempoOrd][tempoAbs].joueur == bushi->joueur){
					aSaute=1;
					}
					
					if(plateau->pions[tempoOrd][tempoAbs].joueur != bushi->joueur)
					{
					aSaute=-1;
					}
					
					tempoAbs=(bushi->abs)+2*j;
					tempoOrd=(bushi->ord)+2*i;
					moove[k]=(plateau->pions[tempoOrd][tempoAbs]);
					affiche_bushi(moove[k]);
					moove[k].jouable=aSaute;
					k++;
				}
				break;
				
				
			default : break;
			
			}
		}
	}
			
			
	
	/*for(i=0; i<k; i++){
		printf("%d. ",i+1);
		affiche_bushi(moove[i]);
		
	}*/
	
	return k;			
	
}	




//Renvoie le type de la case
int est_valide(Plateau *plateau,Bushi bushi, int x, int y)
{
	int tempoAbs=(bushi.abs)+y;
	int tempoOrd=(bushi.ord)+x;
	int resul=-1;
	//On s'assure que la case testée est dans le plateau
	if(tempoAbs < N && tempoAbs >=0 && tempoOrd < N && tempoOrd >= 0){ 
		resul=plateau->pions[tempoOrd][tempoAbs].type;
	}
		
	
	//printf ("la validité de la case (%d,%d) vaut %d\n",tempoAbs,tempoOrd,resul);
	return resul;
}


//En debut de tour, remet tout les bushi du joueur à jouable
void resetJouable(Plateau *plateau,int joueur){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(plateau->pions[i][j].joueur==joueur){
				plateau->pions[i][j].jouable=1;
			}
		}
	}
}

//L'attribut jouable de bushiDestination indique si le bushi saute pendant son délacement.
void effectuer_deplacement(Plateau* plateau,Bushi* bushiBouge,Bushi bushiDestination){
	printf("\nDestination in effectuer_deplacement\n");
	affiche_bushi(bushiDestination);
	
	switch(bushiDestination.jouable){
		
		case 0 : 
			bushiBouge->abs=bushiDestination.abs;
			bushiBouge->ord=bushiDestination.ord;
			//affiche_bushi_coord(bushiBouge);
			printf("Adresse du bushi deplace dans effectuer_deplacement : %p \n",bushiBouge);
			affiche_bushi_coord(bushiBouge);
			
			break;
		default : 
			printf("Unexpected error in effectuer_deplacement\n");
		}
	
	
}


void tour_joueur(Plateau *plateau,int joueur){
	Bushi bushiDestination;
	resetJouable(plateau,joueur);
	Bushi* bushiBouge=NULL;
	
	do{
	affiche_plateau(plateau);
	bushiBouge=bushi_joueur(plateau, joueur);
	printf("Adresse du bushi deplace dans tour_joueur : %p \n",bushiBouge);
	affiche_plateau(plateau);
	bushiDestination=deplacement_bushi(plateau,bushiBouge);
	printf("Destination in tour_jouer\n");
	affiche_bushi(bushiDestination);
	}while(bushiDestination.abs==0 && bushiDestination.ord==0);//Permet de changer d'avis concernant le Bushi que l'on souhaite déplacer
	
	effectuer_deplacement(plateau,bushiBouge,bushiDestination);
	affiche_plateau(plateau);
	
	
}
	
