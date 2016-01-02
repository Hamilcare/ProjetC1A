CC = gcc
OPTIONS = 

# Indique les dépendances :
ShingShang:  plateau.o mainValentin.o bushi.o save.o
	$(CC) $(OPTIONS)  save.o bushi.o plateau.o mainValentin.o -o ShingShang

# Compile les dépendances

bushi.o : include.h bushi.h bushi.c
	$(CC) -c $(OPTIONS)  bushi.c -o bushi.o

plateau.o : include.h couleur.h plateau.h bushi.h bushi.o plateau.c
	$(CC) -c $(OPTIONS)  plateau.c -o plateau.o

save.o : include.h save.c
	$(CC) -c $(OPTIONS) save.c -o save.o

mainValentin.o : include.h mainValentin.c
	$(CC) -c $(OPTIONS) mainValentin.c -o mainValentin.o 


clean : 
	rm -f *.o ShingShang
