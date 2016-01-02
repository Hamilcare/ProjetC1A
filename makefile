CC = gcc
OPTIONS = -Wall -Werror

# Indique les dépendances :
ShingShang:  plateau.o mainValentin.o bushi.o save.o
	$(CC) $(OPTIONS)  save.o bushi.o plateau.o mainValentin.o -o ShingShang

# Compile les dépendances

bushi.o : include.h bushi.h bushi.c
	$(CC) $(OPTIONS)  bushi.c

plateau.o : include.h couleur.h plateau.h bushi.h bushi.o plateau.c
	$(CC) $(OPTIONS)  plateau.c

save.o : include.h save.c

mainValentin.o : include.h bushi.h bushi.o plateau.h couleur.h plateau.o save.o mainValentin.c 
	$(CC) $(OPTIONS)  bushi.o plateau.o mainValentin.c

clean : 
	rm *.o
