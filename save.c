
#include "plateau.h"
#include <unistd.h>
#include <signal.h>
 
#define         SAVE_FILE       "save.shingshang"

Plateau plateau;
 
 
//On sauvegarde l'état du plateau dans le fichier binaire SAVE_FILE à l'aide de fwrite
void            save( void )
{
        FILE  *file;
 
        if ((file = fopen(SAVE_FILE, "w+")) == NULL) {
                perror("fopen() ");
                return ;
        }
        fwrite(&plateau , sizeof(plateau) , 1 , file);
        fclose(file);
}
 
//On charge l'état du plateau depuis un fichier binaire à l'aide de fread
void            load( void )
{
        FILE  *file;
 
        if ((file = fopen(SAVE_FILE, "r")) == NULL) {
                perror("fopen() ");
                return ;
        }
        fread(&plateau , sizeof(plateau) , 1 , file);
        fclose(file);
        //unlink(SAVE_FILE);
}
 
 /*
  * Cette fonction est appele quand l'utilisateur fait ctrl+c
  * On peut alors sauvegarder la partie puis quitter ou non le jeu
  */
 
void            save_and_quit(int signal)
{
        char answer;
 
        puts("Une partie est en cours d'execution\nSauvergarder ? [y : n]");
        do {
                answer = getchar();
        } while (answer != 'y' && answer != 'n');
        
        if (answer == 'y'){
                save();
                
                printf("Voulez vous continuer la partie ? [y : n]");
                do {
					answer = getchar();
				}while (answer != 'y' && answer != 'n');
				if (answer=='y'){
					(void)signal;
				}
				if(answer=='n'){
					exit(0);
				}
			}
			
			if (answer == 'n'){
				printf("Voulez vous continuer la partie ? [y : n]");
                do {
					answer = getchar();
				}while (answer != 'y' && answer != 'n');
				if (answer=='y'){
					(void)signal;
				}
				if (answer=='n'){
					exit(0);
				}
			}

				
        
}
 
