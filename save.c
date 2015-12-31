
#include "plateau.h"
#include <unistd.h>
#include <signal.h>
 
#define         SAVE_FILE       "save.shingshang"

Plateau plateau;
 
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
 
void            handle_signal(int signal)
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
 
