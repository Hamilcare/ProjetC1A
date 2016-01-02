#include "include.h"
#include "couleur.h"
#include "plateau.h"
#include "bushi.h"
#include <signal.h>
#include <unistd.h>


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
	
	char answer;
	int gagne;
	
	 /* si l'utilisateur essaye d'interrompre le programme avec [ctrl + c], 
	  * le programme executera la fonction handle_signal à la place du 
	  * comportement par défaut d'un [ctrl + c], qui est de terminer 
	  * le programme.
	  * SIGINT correspond au signal envoyé par le système lors d'un [ctrl + c]
	  */
	signal(SIGINT, &save_and_quit); 

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
	plateau.quiJoue++;
    gagne=tour_joueur(&plateau);
    //La partie continue tant que personne n'a gagne
    }while(gagne==0);
    system("clear");
    switch(plateau.quiJoue%2+1){
		case 1 :
			setcolor(RED);	
		  
 			puts("    /$$    /$$ /$$             /$$               /$$                         ");
 			puts("   | $$   | $$|__/            | $$              |__/                         ");
 			puts("   | $$   | $$ /$$  /$$$$$$$ /$$$$$$    /$$$$$$  /$$  /$$$$$$   /$$$$$$      ");
 			puts("   |  $$ / $$/| $$ /$$_____/|_  $$_/   /$$__  $$| $$ /$$__  $$ /$$__  $$     ");
 			puts("    \\  $$ $$/ | $$| $$        | $$    | $$  \\ $$| $$| $$  \\__/| $$$$$$$$     ");
 			puts("     \\  $$$/  | $$| $$        | $$ /$$| $$  | $$| $$| $$      | $$_____/     ");
 			puts("      \\  $/   | $$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$| $$      |  $$$$$$$     ");
 			puts("       \\_/    |__/ \\_______/   \\___/   \\______/ |__/|__/       \\_______/     ");
 			puts("                                                                             ");
 			puts("                                                                             ");
 			puts("                                                                             ");
 			puts("                      /$$$$$$$                                               ");
 			puts("                     | $$__  $$                                              ");
 			puts("                     | $$  \\ $$ /$$   /$$                                    ");
 			puts("                     | $$  | $$| $$  | $$                                    ");
 			puts("                     | $$  | $$| $$  | $$                                    ");
 			puts("                     | $$  | $$| $$  | $$                                    ");
 			puts("                     | $$$$$$$/|  $$$$$$/                                    ");
 			puts("                     |_______/  \\______/                                     ");
 			puts("                                                                             ");
 			puts("                                                                             ");
 			puts("                                                                             ");
 			puts("       /$$$$$                                                           /$$  ");
 			puts("      |__  $$                                                         /$$$$  ");
 			puts("         | $$  /$$$$$$  /$$   /$$  /$$$$$$  /$$   /$$  /$$$$$$       |_  $$  ");
 			puts("         | $$ /$$__  $$| $$  | $$ /$$__  $$| $$  | $$ /$$__  $$        | $$  ");
 			puts("    /$$  | $$| $$  \\ $$| $$  | $$| $$$$$$$$| $$  | $$| $$  \\__/        | $$  ");
 			puts("   | $$  | $$| $$  | $$| $$  | $$| $$_____/| $$  | $$| $$              | $$  ");
 			puts("   |  $$$$$$/|  $$$$$$/|  $$$$$$/|  $$$$$$$|  $$$$$$/| $$             /$$$$$$");
 			puts("    \\______/  \\______/  \\______/  \\_______/ \\______/ |__/            |______/");
 			puts("                                                                             ");
 			puts("                                                                             ");
 			puts("                                                                             ");
 			puts("                 /$$$$$$   /$$$$$$        /$$      /$$ /$$$$$$$              ");
 			puts("                /$$__  $$ /$$__  $$      | $$  /$ | $$| $$__  $$             ");
 			puts("               | $$  \\__/| $$  \\__/      | $$ /$$$| $$| $$  \\ $$             ");
 			puts("               | $$ /$$$$| $$ /$$$$      | $$/$$ $$ $$| $$$$$$$/             ");
 			puts("               | $$|_  $$| $$|_  $$      | $$$$_  $$$$| $$____/              ");
 			puts("               | $$  \\ $$| $$  \\ $$      | $$$/ \\  $$$| $$                   ");
 			puts("               |  $$$$$$/|  $$$$$$/      | $$/   \\  $$| $$                   ");
 			puts("                \\______/  \\______/       |__/     \\__/|__/                   ");
 			puts("                                                                             ");
 			puts("                                                                             ");
 			puts("                                                                             ");
		setcolor(WHITE);
		break;
		
		case 2 : 
			setcolor(BLUE);
			puts("   $$\\    $$\\ $$\\             $$\\               $$\\                            ");
			puts("   $$ |   $$ |\\__|            $$ |              \\__|                           ");
			puts("   $$ |   $$ |$$\\  $$$$$$$\\ $$$$$$\\    $$$$$$\\  $$\\  $$$$$$\\   $$$$$$\\         ");
			puts("   \\$$\\  $$  |$$ |$$  _____|\\_$$  _|  $$  __$$\\ $$ |$$  __$$\\ $$  __$$\\        ");
			puts("    \\$$\\$$  / $$ |$$ /        $$ |    $$ /  $$ |$$ |$$ |  \\__|$$$$$$$$ |       ");
			puts("     \\$$$  /  $$ |$$ |        $$ |$$\\ $$ |  $$ |$$ |$$ |      $$   ____|       ");
			puts("      \\$  /   $$ |\\$$$$$$$\\   \\$$$$  |\\$$$$$$  |$$ |$$ |      \\$$$$$$$\\        ");
			puts("       \\_/    \\__| \\_______|   \\____/  \\______/ \\__|\\__|       \\_______|       ");
			puts("                                                                               ");
			puts("                                                                               ");
			puts("                                                                               ");
			puts("                     $$$$$$$\\                                                  ");
			puts("                     $$  __$$\\                                                 ");
			puts("                     $$ |  $$ |$$\\   $$\\                                       ");
			puts("                     $$ |  $$ |$$ |  $$ |                                      ");
			puts("                     $$ |  $$ |$$ |  $$ |                                      ");
			puts("                     $$ |  $$ |$$ |  $$ |                                      ");
			puts("                     $$$$$$$  |\\$$$$$$  |                                      ");
			puts("                     \\_______/  \\______/                                       ");
			puts("                                                                               ");
			puts("                                                                               ");
			puts("                                                                               ");
			puts("      $$$$$\\                                                          $$$$$$\\  ");
			puts("      \\__$$ |                                                        $$  __$$\\ ");
			puts("         $$ | $$$$$$\\  $$\\   $$\\  $$$$$$\\  $$\\   $$\\  $$$$$$\\        \\__/  $$ |");
			puts("         $$ |$$  __$$\\ $$ |  $$ |$$  __$$\\ $$ |  $$ |$$  __$$\\        $$$$$$  |");
			puts("   $$\\   $$ |$$ /  $$ |$$ |  $$ |$$$$$$$$ |$$ |  $$ |$$ |  \\__|      $$  ____/ ");
			puts("   $$ |  $$ |$$ |  $$ |$$ |  $$ |$$   ____|$$ |  $$ |$$ |            $$ |      ");
			puts("   \\$$$$$$  |\\$$$$$$  |\\$$$$$$  |\\$$$$$$$\\ \\$$$$$$  |$$ |            $$$$$$$$\\ ");
			puts("    \\______/  \\______/  \\______/  \\_______| \\______/ \\__|            \\________|");
			puts("                                                                               ");
			puts("                                                                               ");
			puts("                                                                               ");
			puts("                $$$$$$\\   $$$$$$\\        $$\\      $$\\ $$$$$$$\\                 ");
			puts("               $$  __$$\\ $$  __$$\\       $$ | $\\  $$ |$$  __$$\\                ");
			puts("               $$ /  \\__|$$ /  \\__|      $$ |$$$\\ $$ |$$ |  $$ |               ");
			puts("               $$ |$$$$\\ $$ |$$$$\\       $$ $$ $$\\$$ |$$$$$$$  |               ");
			puts("               $$ |\\_$$ |$$ |\\_$$ |      $$$$  _$$$$ |$$  ____/                ");
			puts("               $$ |  $$ |$$ |  $$ |      $$$  / \\$$$ |$$ |                     ");
			puts("               \\$$$$$$  |\\$$$$$$  |      $$  /   \\$$ |$$ |                     ");
			puts("                \\______/  \\______/       \\__/     \\__|\\__|                     ");
			puts("                                                                               ");
			puts("                                                                               ");
			puts("                                                                               ");
			setcolor(WHITE);
			break;
    
	default:break;
	}
       
        return 0;
}
