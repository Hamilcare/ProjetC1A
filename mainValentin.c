#include "cellule.h"
#include "plateau.h"
#include "bushi.h"
 
int main (void){
       
        Cellule plateau[N][N];
        Bushi pions[M];
       
       
       
        Cellule c;
        Cellule b;
        init_cellule(&c);
        printf("*-----Test init_cellule-----*\n");
        affiche_cellule(c);  
        b=build_cellule(1,5,5,0,0);
        printf("*-----Test init_cellule-----*\n");
        affiche_cellule(b);
        init_plateau(plateau);
        charger_partie("configstandard.txt",plateau,pions);     
	affiche_plateau(plateau);
       
       
       
       
        return 0;
}
