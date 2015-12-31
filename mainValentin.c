#include "include.h"
#include "plateau.h"
#include "bushi.h"
#include <signal.h>
#include <unistd.h>
void handle_signal(int signal);
void load();

int main (void){
	
puts("	ad88888ba   88           88                             ad88888ba   88                                                     ad888888b,     ,a8888a,        ,a8888a,        ,a8888a,   ");  
puts("d8"     "8b  88           ""                            d8"     "8b  88                                                    d8"     "88   ,8P"'  `"Y8,    ,8P"'  `"Y8,    ,8P"'  `"Y8,  "); 
puts("Y8,          88                                         Y8,          88                                                            a8P  ,8P        Y8,  ,8P        Y8,  ,8P        Y8,  ");
puts("`Y8aaaaa,    88,dPPYba,   88  8b,dPPYba,    ,adPPYb,d8  `Y8aaaaa,    88,dPPYba,   ,adPPYYba,  8b,dPPYba,    ,adPPYb,d8          aad8"   88          88  88          88  88          88  ")
puts("  `"""""8b,  88P'    "8a  88  88P'   `"8a  a8"    `Y88    `"""""8b,  88P'    "8a  ""     `Y8  88P'   `"8a  a8"    `Y88          ""Y8,   88          88  88          88  88          88  ");
puts("        `8b  88       88  88  88       88  8b       88          `8b  88       88  ,adPPPPP88  88       88  8b       88             "8b  `8b        d8'  `8b        d8'  `8b        d8'  ");
puts("Y8a     a8P  88       88  88  88       88  "8a,   ,d88  Y8a     a8P  88       88  88,    ,88  88       88  "8a,   ,d88     Y8,     a88   `8ba,  ,ad8'    `8ba,  ,ad8'    `8ba,  ,ad8'   ");
puts(" "Y88888P"   88       88  88  88       88   `"YbbdP"Y8   "Y88888P"   88       88  `"8bbdP"Y8  88       88   `"YbbdP"Y8      "Y888888P'     "Y8888P"        "Y8888P"        "Y8888P"     ")
puts("                                            aa,    ,88                                                      aa,    ,88                                                                  ");
puts("                                             "Y8bbdP"                                                        "Y8bbdP"                                                                   "):
	
	
	
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
