#include "include.h"
#include "plateau.h"
#include "bushi.h"
#include <signal.h>
#include <unistd.h>
void handle_signal(int signal);
void load();

int main (void){
	srand(time(NULL));
	int test,i,j;
	signal(SIGINT, &handle_signal);

	FILE *fichier = NULL;
	fichier = fopen("save.shingshang",  "r");
	
	if (fichier)
	{
		puts("starfoullah ya une sauvegarde de mort");
		load();
	}
	else
	{
		init_plateaubis(&plateau);
		for (i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
			{
				affiche_bushi_coord(&(plateau.pions[i][j]));
			}
		}
		getchar();
	
		nouvelle_partie(&plateau);
		for (i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
			{
				affiche_bushi_coord(&(plateau.pions[i][j]));
			}
		}
		getchar();
	}
	
	
	
	//save();
	
	
    //do{
    test=tour_joueur(&plateau, 1);
    //}while(1);
       
       
        return 0;
}
