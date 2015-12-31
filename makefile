# Indique les dépendances :
principal:  plateau.o mainValentin.o bushi.o save.o
	gcc  bushi.o plateau.o mainValentin.o -o principal

# Compile les dépendances

bushi.o : include.h bushi.h bushi.c
	gcc -c  bushi.c

plateau.o : include.h couleur.h plateau.h bushi.h bushi.o plateau.c
	gcc -c  plateau.c

save.o : include.h save.c

mainValentin.o : include.h bushi.h bushi.o plateau.h plateau.o save.o mainValentin.c 
	gcc -c  bushi.o plateau.o mainValentin.c

clean : 
	rm *.o
