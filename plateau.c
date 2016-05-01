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

//Initialise le plateau en plaçant toutes les cases à BLOCKED ou EMPTY
//Plus rapide que la v1
void init_plateaubis(Plateau *plateau)
{
	int commence;
	int i, j;
	
	//On gère les cas où on est sur que la case est EMPTY
	for (i = 0; i < N; i++)
	{
		for(j = 1; j < N - 1; j++)
		{
			plateau->pions[i][j] = EMPTY(i,j);
		}	
	}
	
	//On gère les colonnes où des cases EMPTY et BLOCKED cohabitent
	//a savoir les colonnes A et J
	for (i = 0; i < N; i++)
	{
		plateau->pions[i][0]  = ((i == 4 || i == 5) ? EMPTY(i,0) : BLOCKED(i,0));
		plateau->pions[i][N - 1] = ((i == 4 || i == 5) ? EMPTY(i,N-1) : BLOCKED(i,N-1));
	}
	
	//On détermine ici de manière aléatoire le joueur qui va jouer en premier
	commence = (rand() % (100 - 0 + 1));
	plateau->quiJoue=commence%2;
	
}



//Affichage du plateau 
//Gestion de la couleur des pions
void affiche_plateau(Plateau *plateau)
{
	int joueur=(plateau->quiJoue)%2+1;
	
	system("clear");
	if(joueur==1){
		setcolor(RED);
			puts("	          _                               __      ");
			puts("	         | |                             /_ |		");
			puts("	         | | ___  _   _  ___ _   _ _ __   | |		");
			puts("	     _   | |/ _ \\| | | |/ _ \\ | | | '__|  | |	");
			puts("	    | |__| | (_) | |_| |  __/ |_| | |     | |		");
			puts("	     \\____/ \\___/ \\__,_|\\___|\\__,_|_|     |_|");
		setcolor(WHITE);
	}
	
	else{
		setcolor(BLUE);
			puts("	          _                               ___  ");
			puts("	         | |                             |__ \\ ");
			puts("	         | | ___  _   _  ___ _   _ _ __     ) |");
			puts("	     _   | |/ _ \\| | | |/ _ \\ | | | '__|   / / ");
			puts("	    | |__| | (_) | |_| |  __/ |_| | |     / /_ ");
			puts("	     \\____/ \\___/ \\__,_|\\___|\\__,_|_|    |____|");
			puts("	                                               ");
		setcolor(WHITE);
	}
	
	int i,j,k,numero;
    char *color;
 
		
    
 
    puts("        ---------------------------------------------------      ");
    puts("        | AA | BB | CC | DD | EE | FF | GG | HH | II | JJ |      ");
    puts("        | AA | BB | CC | DD | EE | FF | GG | HH | II | JJ |      ");
    puts("        ---------------------------------------------------      ");
    puts("------       -----------------------------------------           ");
    for (i = 0; i < N; i++)
    {
        for (k = 0; k < 2; k++)
        {
			//On formate l'affichage afin de gérer l'alignement
            printf("| %0.2d |  ", i);
            for(j = 0; j < N; j++)
            {
    
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
            puts("------  ---------------------------------------------------");
        else
            puts("------       -----------------------------------------      ");
    }
}

//Même principe que affiche plateau (dommage qu'il n'y ai pas de surcharge en c)
//On affiche en vert le Bushi que l'on souhaite déplacer ainsi que les cases qui'il peut atteindre
/* Bushi* bushiBouge --> pointe sur le bushi que l'on souhaite bouger
 * Bushi* tab --> tableau de Bushi contenant l'ensemble des arrivées possible pour bushiBouge
 * int taille --> nombre d'éléments dans tab
 */
void affiche_plateau_deplacement(Plateau *plateau,Bushi* bushiBouge, Bushi* tab,int taille)
{
	int joueur=(plateau->quiJoue)%2+1;
	system("clear");
	if(joueur==1){
		setcolor(RED);
			puts("	          _                               __      ");
			puts("	         | |                             /_ |		");
			puts("	         | | ___  _   _  ___ _   _ _ __   | |		");
			puts("	     _   | |/ _ \\| | | |/ _ \\ | | | '__|  | |	");
			puts("	    | |__| | (_) | |_| |  __/ |_| | |     | |		");
			puts("	     \\____/ \\___/ \\__,_|\\___|\\__,_|_|     |_|");
		setcolor(WHITE);
	}
	
	else{
		setcolor(BLUE);
			puts("	          _                               ___  ");
			puts("	         | |                             |__ \\ ");
			puts("	         | | ___  _   _  ___ _   _ _ __     ) |");
			puts("	     _   | |/ _ \\| | | |/ _ \\ | | | '__|   / / ");
			puts("	    | |__| | (_) | |_| |  __/ |_| | |     / /_ ");
			puts("	     \\____/ \\___/ \\__,_|\\___|\\__,_|_|    |____|");
			puts("	                                               ");
		setcolor(WHITE);
	}
    int i,j,k,numero;
    char *color;
 
    puts("        ---------------------------------------------------      ");
    puts("        | AA | BB | CC | DD | EE | FF | GG | HH | II | JJ |      ");
    puts("        | AA | BB | CC | DD | EE | FF | GG | HH | II | JJ |      ");
    puts("        ---------------------------------------------------      ");
    puts("------       -----------------------------------------           ");
    for (i = 0; i < N; i++)
    {
        for (k = 0; k < 2; k++)
        {
            printf("| %0.2d |  ", i);
            for(j = 0; j < N; j++)
            {
				numero=0;
    
                if (j == 0 && plateau->pions[i][j].type != -1)
                    printf("|");
                    
                    numero=est_dans(plateau->pions[i][j],tab,taille);
                    //Permet d'afficher le bushi selectionne et dont on affiche les déplacements en Jaune
                    if(&(plateau->pions[i][j])==bushiBouge){
						color=YELLOW;
					}
					//Permet d'afficher les destination possible en vert
					else if(numero!=-1){
						color=GREEN;
					}
					else{
						color = ((plateau->pions[i][j].joueur == 1) ? RED : BLUE);
					}
                setcolor(color);
                switch(plateau->pions[i][j].type)
                {
                    case -2 :
						if(color==GREEN){
							printf(" %0.2d ",numero+1);
						}
						else{
							printf(" PP ");
							}
						break;
                    case -1 : printf("     "); break;
                    
                    //On affiche le numero a rentrer pour atteindre la case
                    case 0 : 
						if(numero==-1){
						printf("    ");
						}
						else{
							printf(" %0.2d ",numero+1);
							}
					   break;
                    
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
            puts("------  ---------------------------------------------------");
        else
            puts("------       -----------------------------------------      ");
    }
}



//Place les bushis spécifiés dans le fichier txt selectionné
void nouvelle_partie(Plateau *plateau){
	int choix;
	FILE* fichier = NULL;
	
	//On choisit la situation que l'on va démarrer 
	do{
		printf("\nQuel type de partie souhaitez vous lancer?\n");
		printf("1.Partie standard\n");
		printf("2.Situation ShingShang\n");
		printf("3.Partie perdue par prise d'un portail\n");
		printf("4.Partie perdue par perte dragon\n");
		printf("5.Demonstration saut\n");
		scanf("%d",&choix);
		empty_buffer();
	}while(choix <=0 || choix >5);
	
	//On ouvre le fichier texte contenant les données correspondantes à la situation choisie
	switch (choix){
		case 1: fichier = fopen("standard.txt", "r"); break;
		case 2: fichier = fopen("shingshang.txt", "r");break;
		case 3: fichier = fopen("perdrePortail.txt", "r");break;
		case 4: fichier = fopen("perdreDragon.txt", "r");break;
		case 5: fichier = fopen("demoSaut.txt", "r");break;
		default: break;
	}
	
	
				
	
	
	//L'ouverture du fichier s'est bien déroulée
	if (fichier != NULL){
		
		printf("L'ouverture du fichier s'est bien déroulée\n");
		int tmp[5]; //Ce tableau contient la valeur des différents attributs d'un bushi lu depuis pions.txt
					//Dans l'ordre type,abscisse, ordonnee, joueur, jouable
					
		/* On lit ligne par ligne le fichier et on stock les nombres de la ligne dans tmp*/
		while(fscanf(fichier,"%d %d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4])!=EOF){
		
			Bushi test;
			/*On crée un bushi à partir de tmp donc des données contenu dans le fichier */
			test=MAKEBUSHI(tmp[0],tmp[1], tmp[2], tmp[3], tmp[4]);
			//On ajoute le bushi au plateau
			plateau->pions[tmp[2]][tmp[1]]=test;
			
			
		
		}
		
		
		
		
		fclose(fichier);
	}
	
	else {
		printf("Erreur lors de l'ouverture du fichier \n");
	}
	
}



/*Affichela liste des bushis encore en jeu et jouable du joueur passé en paramètre
 * Renvoie un pointeur sur le bushi que le joueur désire bouger
 * Renvoie NULL si le joueur ne peut jouer aucun bushi
 * Plateau *plateau --> Le plateau de jeu
 */
 
Bushi* bushi_joueur(Plateau *plateau)
{		
		int joueur=plateau->quiJoue%2+1;
		int i,j;
		int k=0;
		int choix = -1;
		Bushi* tab[NBMAXBUSHIS];
		
		
		/* Parcourt le plateau de jeu et stocke dans tab 
		 * les pointeurs sur les bushis du joueur courant
		 */
		for(i=0; i<N; i++){
			for(j=0; j<N; j++){
				if(plateau->pions[i][j].joueur==joueur && plateau->pions[i][j].type != -2 && (plateau->pions[i][j].jouable==1 || plateau->pions[i][j].jouable==2)){
					tab[k]=&(plateau->pions[i][j]);
				
					k++;//k représente le nombre de bushi jouable par le joueur courant
					
				}
			}
		}
		
		//Affiche la liste des bushis jouable
		if(k!=0){
			printf("Liste des bushis que vous pouvez jouer : %d différents \n",k);
			for(i=0;i<k;i++){
				printf("%0.2d. ",i+1);
				affiche_bushi_coord(tab[i]);
				if((i+1)%6==0){
					printf("\n");
				}
			
			}
		
		
			//Le joueur sélectionne le bushi qu'il veut jouer
			while(choix<=0 || choix>k){
				printf("\nSelectionnez le bushi que vous souhaitez déplacer\n");
				scanf("%d",&choix);
				empty_buffer();
			}
			//printf("Adresse du pointeur renvoyé : %p\n",tab[choix-1]);
			return tab[choix-1];
		}
		//Aucun bushi jouable
		else{
			printf("Vous ne pouvez jouer aucun bushi, c'est la fin de votre tour \n");
			return NULL;
		}
		
}




/* Bushi* bushi -> pointe sur le bushi que l'on souhaite 
 * Renvoi le bushi correspondant à la case d'arrivée 
 */
Bushi deplacement_bushi(Plateau *plateau,Bushi *bushi)
{
	int i,k;
	int choix=-10;
	//Ce tableau va stocker tous les déplacements possibles du bushi
	Bushi move[DEPLACEMENTSMAX];
	//On appelle la fonction qui gère les déplacements possibles en fonction du type de bushi
	switch(bushi->type){
		case 1 : k=deplacement_singe(plateau, bushi, move);break;
		case 2 : k=deplacement_lion(plateau, bushi, move);break;
		case 3 : k=deplacement_dragon(plateau, bushi, move);break;
		default : break;
	}
	
	
	//On affiche les déplacements possible du bushi
	affiche_plateau_deplacement(plateau,bushi,move,k);
	
	
	//On affiche des options supplémentaires en dessous du tableau
	printf("%0.2d. Changer de Bushi ",0);
	printf("-1. Passer votre tour\n",-1);
	
	/*
	 * On gère ici le choix de la destination du bushi par le joueur
	 */
	while(choix<-1 || choix>k+1){
		printf("\nSelectionnez votre case d'arrivée\n");
		scanf("%d",&choix);
		empty_buffer();
	}
	
	if(choix==-1){
		return EMPTY(-1,-1);
	}
	
	if(choix==0){
		return EMPTY(0,0);
	}
	
	else{
		return move[choix-1];
	}
		
}

/* Affichage pour debug
void affiche_bis(Plateau *plateau){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d",plateau->pions[i][j].type);
		}
		printf("\n");
	}
}


void affiche_ter(Plateau *plateau){
	int i,j;
	for(i=0,i<N,i++){
		for(j=0,j<N,j++){
			affiche_bushi_coord(&(plateau->pions[i][j]));
		}
		printf("\n");
	}
}
*/




/*
 * Gère les déplacements possibles pour un singe
 * Bushi *bushi -> le bushi dont on souhaite connaitre les deplacements possibles
 * Bushi move[] -> tableau dans lequel seront stockees les deplacements possibles
 * 
 * return int -> renvoie le nombre de deplacements possibles ie le nombre d'elements dans move
 */

int deplacement_singe(Plateau *plateau,Bushi *bushi, Bushi move[])
{
	
	int i,j;
	int k=0;//index du tableau move
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
			
			/* le test bushi->jouable==1 permet de s'assurer que le bushi
			 * passe en parametre n'a pas saute un allie au coup d'avant
			 * (dans ce cas jouable vaudrait 2)
			 */
			
				if(bushi->jouable==1){
					tempoAbs=(bushi->abs)+j;
					tempoOrd=(bushi->ord)+i;
					move[k]=(plateau->pions[tempoOrd][tempoAbs]);
					k++;
					
						
				//On teste la case un coup plus loin dans l'alignement
					valide=est_valide(plateau, *bushi, 2*i, 2*j);
				
					if(valide==0){
						tempoAbs=tempoAbs+j;
						tempoOrd=tempoOrd+i;
						move[k]=(plateau->pions[tempoOrd][tempoAbs]);
						k++;
					}
				}
				break;
	
			//la case est occupee par un singe, on regarde celle d'apres
			//pour voir si un saut est possible
			case 1 :
			if(valide==1){
					
				valide=est_valide(plateau, *bushi, 2*i, 2*j);
				if(valide==0){
					tempoAbs=(bushi->abs)+j;
					tempoOrd=(bushi->ord)+i;
					
					//on determine si le pions saute est allie ou ennemi
					if(plateau->pions[tempoOrd][tempoAbs].joueur == bushi->joueur){
					
						aSaute=1;
					}
					
					if(plateau->pions[tempoOrd][tempoAbs].joueur != bushi->joueur)
					{
						aSaute=-1;
					}
					
					tempoAbs=(bushi->abs)+2*j;
					tempoOrd=(bushi->ord)+2*i;
					move[k]=(plateau->pions[tempoOrd][tempoAbs]);
					//affiche_bushi(move[k]);
					move[k].jouable=aSaute;
					k++;
				}
				break;
			}
				
			default : break;
			
			}
		}
	}
			
			
	
	
	
	return k;			
	
}




/*Meme principe que deplacement singe
 * avec les specificites du Lion
 */
int deplacement_lion(Plateau *plateau,Bushi *bushi, Bushi move[]){
	
	int i,j;
	int k=0;//index du tableau move
	int valide=0;
	int tempoAbs=0;
	int tempoOrd=0;
	int aSaute=0;//0 pas de saut / -1 saut d'un ennemi / 1 saut d'un allie
	
	
	for(i=1; i>=-1; i--){
		
		for(j=1; j>=-1; j--){
			
			valide=est_valide(plateau,*bushi,i,j);
			
			if(valide==0 && bushi->jouable==1){
				tempoAbs=(bushi->abs)+j;
				tempoOrd=(bushi->ord)+i;
				move[k]=(plateau->pions[tempoOrd][tempoAbs]);
				k++;
			}
			
			// si la case est occupee par un singe ou un lion
			else if (valide==1 || valide==2){
				valide=est_valide(plateau, *bushi, 2*i, 2*j);
				
				if(valide==0){
					tempoAbs=(bushi->abs)+j;
					tempoOrd=(bushi->ord)+i;
					if(plateau->pions[tempoOrd][tempoAbs].joueur == bushi->joueur){
					aSaute=1;
					}
					
					if(plateau->pions[tempoOrd][tempoAbs].joueur != bushi->joueur)
					{
					aSaute=-1;
					}
					
					tempoAbs=(bushi->abs)+2*j;
					tempoOrd=(bushi->ord)+2*i;
					move[k]=(plateau->pions[tempoOrd][tempoAbs]);
					//on stock l'info dans l'attribut jouable du bushi d'arrivee
					move[k].jouable=aSaute;
					k++;
				}
			}
		}
	}
	
	return k;			
	
}

/*Meme principe que deplacement singe
 * avec les specificites du Dragon
 */
int deplacement_dragon(Plateau *plateau,Bushi *bushi, Bushi move[]){
	int i,j;
	int k=0;//index du tableau move
	int valide=0;
	int tempoAbs=0;
	int tempoOrd=0;
	int aSaute=0;//0 pas de saut / -1 saut d'un ennemi / 1 saut d'un allie
	
	
	for(i=1; i>=-1; i--){
		
		for(j=1; j>=-1; j--){
			
			valide=est_valide(plateau,*bushi,i,j);
			//case occupee par un singe/lion/dragon
			if (valide==1 || valide==2 || valide==3){
				valide=est_valide(plateau, *bushi, 2*i, 2*j);
				
				//on check si la case derrière est vide ou est un portail
				if(valide==0||valide==-2){
					tempoAbs=(bushi->abs)+j;
					tempoOrd=(bushi->ord)+i;
					if(plateau->pions[tempoOrd][tempoAbs].joueur == bushi->joueur){
					aSaute=1;
					}
					
					if(plateau->pions[tempoOrd][tempoAbs].joueur != bushi->joueur)
					{
					aSaute=-1;
					}
					
					tempoAbs=(bushi->abs)+2*j;
					tempoOrd=(bushi->ord)+2*i;
					move[k]=(plateau->pions[tempoOrd][tempoAbs]);
					//affiche_bushi(move[k]);
					move[k].jouable=aSaute;
					k++;
				}
			}
		}
	}
	printf("lol\n");
	return k;
}


/*
 * Bushi bushi --> bushi dont on souhaite connaitre les deplacements
 * int i, int j --> nombre a ajouter à l'abscisse et l'ordonnee de bushi
 * pour obtenir les coordonnees de la case que l'on souhaite tester
 * 
 * return int --> renvoie le type de la case testee, ie son contenu */
 
int est_valide(Plateau *plateau,Bushi bushi, int i, int j)
{
	
	int tempoAbs=(bushi.abs)+j	;
	int tempoOrd=(bushi.ord)+i;
	int resul=-1;
	
	
	//On s'assure que la case testée est dans le plateau
	if(tempoAbs < N && tempoAbs >=0 && tempoOrd < N && tempoOrd >= 0){ 
		resul=plateau->pions[tempoOrd][tempoAbs].type;
		
	}
		
	return resul;
}




/* Modifie l'attribut jouable de tous les bushis du joueur
 *
 * int joueur -> le joueur dont on veut modifier les bushis
 * int valeur -> la valeur que doit prendre l'attribut jouable des bushis du joueur
 */

void resetJouable(Plateau *plateau,int joueur,int valeur){
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(plateau->pions[i][j].joueur==joueur){
				
				plateau->pions[i][j].jouable=valeur;
			}
		}
	}
		
}


/* Effectue le déplacement d'un bushi
 * Bushi* bushiBouge-> le bushi qu'on souhaite bouger
 * Bushi bushiDestination -> la destination de bushiBouge
 */
void effectuer_deplacement(Plateau* plateau,Bushi* bushiBouge,Bushi bushiDestination){
		
		int tmpAbs=bushiBouge->abs;
		int tmpOrd=bushiBouge->ord;
		int absEnnemi;
		int ordEnnemi;
		
		//L'attribut jouable de bushiDestination indique si le bushi saute pendant son délacement.
		switch(bushiDestination.jouable){
			
			//On saute par dessus un allie
			case 1 :
				bushiBouge->abs=bushiDestination.abs;
				bushiBouge->ord=bushiDestination.ord;
				
				
				printf("\n");
				
				//On modifie la case d'arrivee
				plateau->pions[bushiBouge->ord][bushiBouge->abs]=*bushiBouge;				
				
				
				bushiBouge=&(plateau->pions[bushiBouge->ord][bushiBouge->abs]);			
	
				//on vide la case de depart
				plateau->pions[tmpOrd][tmpAbs]=EMPTY(tmpOrd,tmpAbs);
				
				resetJouable(plateau,bushiBouge->joueur,0);
				//On indique que le bushi a saute un allie et qu'il ne peut donc se deplacer qu'en sautant jusqu'à la fin du tour
				bushiBouge->jouable=2;
				
				
				break;
		
		//On ne saute pas
		case 0 : 
			
			
			bushiBouge->abs=bushiDestination.abs;
			bushiBouge->ord=bushiDestination.ord;
		
			
			printf("\n");
			plateau->pions[bushiBouge->ord][bushiBouge->abs]=*bushiBouge;
			bushiBouge=&(plateau->pions[bushiBouge->ord][bushiBouge->abs]);
			
			plateau->pions[tmpOrd][tmpAbs]=EMPTY(tmpOrd,tmpAbs);
			
			
			
			
			break;
			
		//On saute par dessus un ennemi	
		case -1 :

			absEnnemi=(tmpAbs+bushiDestination.abs)/2;
	
			ordEnnemi=(tmpOrd+bushiDestination.ord)/2;
		
			
			bushiBouge->abs=bushiDestination.abs;
			bushiBouge->ord=bushiDestination.ord;
	
			//Case d'arrivee
			plateau->pions[bushiBouge->ord][bushiBouge->abs]=*bushiBouge;
			bushiBouge=&(plateau->pions[bushiBouge->ord][bushiBouge->abs]);
			
			//Case depart
			plateau->pions[tmpOrd][tmpAbs]=EMPTY(tmpOrd,tmpAbs);
		
			//On retire l'ennemi saute du jeu
			if(bushiBouge->jouable==2){
				plateau->pions[ordEnnemi][absEnnemi]=EMPTY(ordEnnemi,absEnnemi);
			}
			
			resetJouable(plateau,bushiBouge->joueur,1);
			bushiBouge->jouable=0;
			
			break;
			
		default : 
			printf("Unexpected error in effectuer_deplacement\n");
			break;
		}
	
}



//Gère le tour du jeu du joueur courant
int tour_joueur(Plateau *plateau){	
                
	int joueur=(plateau->quiJoue)%2+1;                            
	int gagne;
	Bushi bushiDestination;
	
	
	Bushi* bushiBouge=NULL;
	int passeSonTour=0;
	
	
	do{
		do{
			affiche_plateau(plateau);
			bushiBouge=bushi_joueur(plateau);
			
			//le joueur a selectionne un bushi
			if(bushiBouge!=NULL){
			
				
				//Le joueur choisit une destination pour le bushi selectionne
				bushiDestination=deplacement_bushi(plateau,bushiBouge);
				
				
				
			}
			//Le joueur ne peut jouer aucun bushi ou passe son tour
			if((bushiDestination.abs==-1 && bushiDestination.ord==-1)|| bushiBouge==NULL){
				bushiDestination.jouable=0;
				passeSonTour=1;
				break;
				}
	
		}//Permet de changer d'avis concernant le Bushi que l'on souhaite déplacer
		// si le joueur souhaite changer de bushi dans deplacement_bushi, celle ci renverra 
		//un bushi EMPTY(0,0)
		while(bushiDestination.abs==0 && bushiDestination.ord==0);
		
		if(passeSonTour==0){
			effectuer_deplacement(plateau,bushiBouge,bushiDestination);
			//affiche_plateau(plateau);
		}
		
		else{
			printf("Vous passez votre tour\n");
			
		}
		
		gagne=a_perdu(plateau,(joueur==1 ? 2 : 1 ));
		printf("gagne ? :%d \n",gagne);
		
	}while(bushiDestination.jouable!=0 && gagne==0); // Tant qu'on saute on continue à jouer
	resetJouable(plateau,joueur,1);
	printf("-----Fin du tour du joueur %d\n",joueur);
	//plateau->quiJoue++;
	
	return gagne;
	
	
}


int a_perdu(Plateau* plateau,int joueur){
	
	printf("JOUEUR : %d \n",joueur);
	int i=0,j=0,resul=0;
	int nbDragons=0;
	int nbPortails=0;
	//On verifie si le joueur n'as plus de dragon
	//On verifie que le joueur à toujours ses deux portails
	while((i<N && (nbDragons<2 || nbPortails<2))){
		j=0;
		while((j<N && (nbDragons<2 || nbPortails<2))){
			
			if(plateau->pions[i][j].type==3 && plateau->pions[i][j].joueur==joueur){
				//printf("J'ai trouvé un dragon : (%d,%d) \n",j,i);
				nbDragons++;
			}
			if(plateau->pions[i][j].type==-2 && plateau->pions[i][j].joueur==joueur){
				//printf("J'ai trouvé un portail : (%d,%d) \n",j,i);
				nbPortails++;
			}
			j++;
		}
		i++;
	}
	
	if(nbDragons ==0){
		printf("Le joueur %d a perdu car il n'a plus de Dragon\n-----GAME OVER-----\n",joueur);
		resul=1;
	}
	else if(nbPortails!=2){
		printf("Le joueur %d a perdu car un de ses portails a été capturé\n-----GAME OVER-----\n",joueur);
		resul=1;
	}
	
	return resul;
}
	
	

			
	
	
	
	
	
	
