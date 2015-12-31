#include "include.h"
#include "plateau.h"
#include "bushi.h"
#include <signal.h>
#include <unistd.h>
void handle_signal(int signal);
void load();

int main (void){
	system("clear");
puts(" _____ _     _             _____ _                         _____  _____  _____  _____ ");
puts("/  ___| |   (_)           /  ___| |                       |____ ||  _  ||  _  ||  _  |");
puts("\\ `--.| |__  _ _ __   __ _\\ `--.| |__   __ _ _ __   __ _      / /| |/' || |/' || |/' |");
puts(" `--. \\ '_ \\| | '_ \\ / _` |`--. \\ '_ \\ / _` | '_ \\ / _` |     \\ \\|  /| ||  /| ||  /| |");
puts("/\\__/ / | | | | | | | (_| /\\__/ / | | | (_| | | | | (_| | .___/ /\\ |_/ /\\ |_/ /\\ |_/ /");
puts("\\____/|_| |_|_|_| |_|\\__, \\____/|_| |_|\\__,_|_| |_|\\__, | \\____/  \\___/  \\___/  \\___/"); 
puts("                      __/ |                         __/ |                             ");
puts("                     |___/                         |___/   ");
	
	
	srand(time(NULL));
	int i,j;
	char answer;
	
	signal(SIGINT, &handle_signal);

	//On vérifie si une sauvegarde existe.
	FILE *fichier = NULL;
	fichier = fopen("save.shingshang",  "r");
	
	if (fichier){
		do{
		puts("Une sauvegarde a ete detectee, souhaitez vous la charger? [y : n]");
		answer=getchar();	
		}while (answer != 'y' && answer != 'n');
		//On charge la sauvegarde
		if(answer=='y'){
		
			puts("Chargement de la partie\n");
			load();
		}
		//on ne la charge pas
		else{
			init_plateaubis(&plateau);
			nouvelle_partie(&plateau);
		}
			
	}
	//Pas de sauvegarde
	else
	{
		puts("Pas de sauvegarde detectee, lancement d'une nouvelle partie");
		init_plateaubis(&plateau);
		
	
		nouvelle_partie(&plateau);
		
	}
	
	
	//Boucle de jeu
    do{
	system("clear");
    tour_joueur(&plateau, plateau.quiJoue%2+1);
    }while(a_perdu(&plateau)==0);
	
       
        return 0;
}
