#include "plateau.h"
#include "couleur.h"

void init_plateau(Bushi (*pions)[N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0; j<N; j++){

			if (j>=1 && j<=8){
				pions[i][j] = MAKEBUSHI(0,j,i,0,0);
			}
			else if(j==0 || j==9){
				if(i==4 || i==5){
					pions[i][j] = MAKEBUShI(0,j,i,0,0);
				}
				else pions[i][j] = MAKEBUSHI(-1,j,i,0,0);
			}
			else {
				pions[i][j] = MAKEBUSHI(-1,j,i,0,0);
			}

		}
	}
}
