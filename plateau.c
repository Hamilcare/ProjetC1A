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
Bushi* bushi_joueur(Plateau *plateau, int joueur)
{
	int i,j;
	int k=0;
	int choix = -1;
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
		printf("%d. ",i+1);
		affiche_bushi_coord(tab[i]);
		
	}
	
	
	while(choix<=0 || choix>k){
		printf("Selectionnez le bushi que vous souhaitez déplacer\n");
		scanf("%d",&choix);
		empty_buffer();
	}
	
	return tab[choix-1];
	
}


void deplacement_bushi(Plateau *plateau,Bushi *bushi)
{
	int i,k;
	Bushi moove[DEPLACEMENTSMAX];
	switch(bushi->type){
		case 1 : k=deplacement_singe(plateau, bushi, moove);break;
		default : break;
	}
	
	
	for(i=0; i<k; i++){
		printf("%d. ",i+1);
		affiche_bushi_coord(&(moove[i]));
		
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
					printf("--La case (%d,%d) est de type %d --\n",tempoAbs,tempoOrd,plateau->pions[tempoOrd][tempoAbs].type);
					printf("---La case (%d,%d) est ajoutee aux deplacements---\n",tempoAbs,tempoOrd);
					
						
					if(est_valide(plateau, *bushi, 2*i, 2*j)==1){
						tempoAbs=tempoAbs+j;
						tempoOrd=tempoOrd+i;
					
						//Si la case située à 2 de distance est libre on l'ajoute au déplacment possible
						if(plateau->pions[tempoOrd][tempoAbs].type==0){
							printf("YOLO\n");
							moove[k]=(plateau->pions[tempoOrd][tempoAbs]);
							affiche_bushi(plateau->pions[tempoOrd][tempoAbs]);
							k++;
							printf("--La case (%d,%d) est de type %d --\n",tempoAbs,tempoOrd,plateau->pions[tempoOrd][tempoAbs].type);
							printf("---La case (%d,%d) est ajoutee aux deplacements---\n",tempoAbs,tempoOrd);
						}
					}

				}
				
				else if (plateau->pions[tempoOrd][tempoAbs].type==1){
					
					if(est_valide(plateau, *bushi, 2*i, 2*j)==1){
						tempoAbs=tempoAbs+j;
						tempoOrd=tempoOrd+i;
					
						//Si la case située à 2 de distance est libre on l'ajoute au déplacment possible
						if(plateau->pions[tempoOrd][tempoAbs].type==0){
							printf("YOLO\n");
							moove[k]=(plateau->pions[tempoOrd][tempoAbs]);
							affiche_bushi(plateau->pions[tempoOrd][tempoAbs]);
							k++;
							printf("--La case (%d,%d) est de type %d --\n",tempoAbs,tempoOrd,plateau->pions[tempoOrd][tempoAbs].type);
							printf("---La case (%d,%d) est ajoutee aux deplacements---\n",tempoAbs,tempoOrd);
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
	
}


int est_valide(Plateau *plateau,Bushi bushi, int x, int y)
{
	int tempoAbs=(bushi.abs)+y;
	int tempoOrd=(bushi.ord)+x;
	int resul=0;
	if(tempoAbs < N && tempoAbs >=0 && tempoOrd < N && tempoOrd >= 0){
		if(plateau->pions[tempoOrd][tempoAbs].type==-1 && plateau->pions[tempoOrd][tempoAbs].type==-2){
			resul=0;
		}
		else{
			resul=1;
		}
	}
	
	printf ("la validité de la case (%d,%d) vaut %d\n",tempoAbs,tempoOrd,resul);
	return resul;
}



		
	
