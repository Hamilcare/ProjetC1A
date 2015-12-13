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
		init_plateau(&plateau);
	}
	affiche_plateau(&plateau);  
       	getchar();
	affiche_plateau(&plateau);       
       
       
       
       
        return 0;
}
