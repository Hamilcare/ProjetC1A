# Indique les dépendances :
principal:  plateau.o mainValentin.o bushi.o save.o
	gcc  bushi.o plateau.o mainValentin.o -o principal

# Compile les dépendances

bushi.o : include.h plateau.h plateau.o bushi.h bushi.c
	gcc -c -Wall bushi.c

plateau.o : include.h couleur.h plateau.h plateau.c
	gcc -c -Wall plateau.c

save.o : include.h save.c

principal.o : mainValentin.c include.h bushi.h bushi.o plateau.h plateau.o save.o
	gcc -c -Wall bushi.o plateau.o mainValentin.c

clean : 
	rm *.o
