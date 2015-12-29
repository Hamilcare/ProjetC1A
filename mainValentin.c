#include "include.h"
#include "plateau.h"
#include "bushi.h"
#include <signal.h>
#include <unistd.h>
void handle_signal(int signal);
void load();

int main (void){

	signal(SIGINT, &handle_signal);

	FILE *fichier = NULL;
	fichier = fopen("save.starfoullah",  "r");
 
	if (fichier)
	{
		puts("starfoullah ya une sauvegarde de mort");
		load();
	}
	else
	{
		init_plateaubis(&plateau);
	}
	//fclose(fichier);	
	affiche_plateau(&plateau);  
       	getchar();
	nouvelle_partie(&plateau);
	
	
	affiche_plateau(&plateau);  
	Bushi* b = bushi_joueur(&plateau, 1);
	affiche_bis(&plateau);
	deplacement_bushi(&plateau,b);   
    affiche_bis(&plateau);
       
       
       
        return 0;
}
