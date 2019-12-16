// Petit programme de démonstration de la mesure de temps de calcul :
// o fonction clock() : retourne le nombre de temps d'horloge utilisés par le programme ;
// o la constante CLOCKS_PER_SEC permet de faire la conversion en secondes.

#include <time.h>
#include <stdio.h>

int main(int argc, char **argv) { int i; double duree_ms;
	clock_t duree = clock() ;
	for(i=0 ; i<100000000 ; i++)  ;
	duree = clock() - duree ;
	duree_ms = duree/(double)CLOCKS_PER_SEC*1000 ;
	printf("fait en %.7fms\n", duree_ms) ;
	return 0;
	}
