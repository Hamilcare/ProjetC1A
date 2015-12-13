#include "plateau.h"
#include "couleur.h"

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
					printf("coucou\n");
			
				}
			}
			else {
				platal->pions[i][j] = MAKEBUSHI(-1,j,i,0,0);
			}

		}
	}
	platal->pions[1][4] = MAKEBUSHI(-2,1,4,0,0);
	platal->pions[1][5] = MAKEBUSHI(-2,1,5,0,0);
	platal->pions[8][4] = MAKEBUSHI(-2,8,4,0,0);
	platal->pions[8][5] = MAKEBUSHI(-2,8,5,0,0);
}

void affiche_plateau(Plateau *platal){
	int i,j;
	for (i=0; i<N; i++){
		for(j=0; j<N; j++){
	//		affiche_bushi(platal.pions[i][j]);
		
			if(platal->pions[i][j].type==0){
				printf("o");

			}
			else if(platal->pions[i][j].type==-1){
				printf("x");
			}
			else if(platal->pions[i][j].type==1){
				printf("S");
			}
			else if(platal->pions[i][j].type==2){
				printf("L");
			}
			else if(platal->pions[i][j].type==3){
				printf("D");
			}
			else if(platal->pions[i][j].type==-2){
				printf("P");
			}
		}
		printf("\n");
	}
}
