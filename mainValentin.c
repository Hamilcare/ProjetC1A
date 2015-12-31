#include "include.h"
#include "plateau.h"
#include "bushi.h"
#include <signal.h>
#include <unistd.h>
void handle_signal(int signal);
void load();

int main (void){
	srand(time(NULL));
	int i,j;
	char answer;
	signal(SIGINT, &handle_signal);

	FILE *fichier = NULL;
	fichier = fopen("save.shingshang",  "r");
	
	if (fichier){
		do{
		puts("Une sauvegarde a ete detectee, souhaitez vous la charger? [y : n]");
		answer=getchar();	
		}while (answer != 'y' && answer != 'n');
		
		if(answer=='y'){
		
			puts("Chargement de la partie\n");
			load();
		}
		else{
			init_plateaubis(&plateau);
			nouvelle_partie(&plateau);
		}
			
	}
	else
	{
		puts("Pas de sauvegarde detectee, lancement d'une nouvelle partie");
		init_plateaubis(&plateau);
		
	
		nouvelle_partie(&plateau);
		
	}
	
	
	
    do{
    tour_joueur(&plateau, plateau.quiJoue%2+1);
    }while(a_perdu(&plateau)==0);
	
       
        return 0;
}
