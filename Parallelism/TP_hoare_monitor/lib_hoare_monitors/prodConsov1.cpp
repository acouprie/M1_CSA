/* CB/UPS/IRIT
 * Producteur-consommateur, essai "moniteurs de Hoare"
 * 
 * Directives pre-processeur : 
 * -DTRACE_SOUHAIT : trace des depots/retraits
 * -DTRACE_THD : creation/desctrution des threads
 * */

#include <unistd.h>
#include <string.h>

#include "PCMonitorv1.h"

// Moniteur "de Hoare" partage par tous les threads
PCMonitorV1 *moniteurPC;

#define NB_FOIS_PROD   5 
#define NB_FOIS_CONSO  5 

#define NB_PROD_MAX   20
#define NB_CONSO_MAX  20

typedef struct {                // Parametre des threads
  unsigned rang;                // - rang de creation
  unsigned typeMsg;             // - type de message a deposer/retirer (si besoin)
  unsigned nbFois;              // - nombre de depots ou de retraits a faire
} Parametres;

/*---------------------------------------------------------------------*/
/* codeErr : code retournee par une primitive
 * msgErr  : message d'erreur personnalise
 * valErr  : valeur retournee par le thread
 */
void thdErreur(int codeErr, const char *msgErr, int valeurErr) {
  int *retour = (int *)malloc(sizeof(int));
  *retour = valeurErr;
  fprintf(stderr, "%s: %d soit %s \n", msgErr, codeErr, strerror(codeErr));
  pthread_exit(retour);
}


/*--------------------------------------------------*/
/* Thread producteur
 */
void * producteur (void *arg) {
  unsigned i;
  PCMonitorV1::TypeMessage leMessage;
  Parametres *param = (Parametres *)arg;

  srand(pthread_self());

  for (i = 0; i < param->nbFois; i++) {
    sprintf (leMessage.info, "%s %d %s %d", "bonjour num ", i, "de prod ", param->rang);
    leMessage.type = param->typeMsg;
    leMessage.rangProd = param->rang;

#ifdef TRACE_SOUHAIT
    printf("\t\tProd %d : Je veux deposer = [T%d] %s (de %d)\n", 
         param->rang, leMessage.type, leMessage.info, leMessage.rangProd);
#endif

    moniteurPC->deposer(leMessage, param->rang);

    //usleep(rand()%(100 * param->rang + 100));
  }
  pthread_exit(NULL);
}

/*--------------------------------------------------*/
/* Thread consommateur
 */
void * consommateur (void *arg) {
  unsigned i;
  PCMonitorV1::TypeMessage unMessage;
  Parametres *param = (Parametres *)arg;

  srand(pthread_self());

  for (i = 0; i < param->nbFois; i++) {

#ifdef TRACE_SOUHAIT
    printf("\t\tConso %d : Je veux retirer un message [%d] \n", param->rang, param->typeMsg);
#endif

    moniteurPC->retirer(&unMessage, param->rang);

    //usleep(rand()%(100 * param->rang + 100));
  }
  pthread_exit(NULL);
}

/*--------------------------------------------------*/
int main(int argc, char *argv[]) {
  unsigned i, etat;
  unsigned nbThds, nbProd, nbConso, nbCases, nbDepots, nbRetraits;
  int *cr;
  Parametres paramThds[NB_PROD_MAX + NB_CONSO_MAX];
  pthread_t idThdProd[NB_PROD_MAX], idThdConso[NB_CONSO_MAX];

  if (argc <= 5) {
    printf ("Usage: %s <Nb Prod <= %d> <Nb Conso <= %d> <Nb Cases <= %d> <NB depots> <Nb retraits>\n", 
             argv[0], NB_PROD_MAX, NB_CONSO_MAX, NB_CASES_MAX);
    exit(2);
  }

  nbProd  = atoi(argv[1]);
  if (nbProd > NB_PROD_MAX)
    nbProd = NB_PROD_MAX;
  nbConso = atoi(argv[2]);
  if (nbConso > NB_CONSO_MAX)
    nbConso = NB_CONSO_MAX;
  nbThds = nbProd + nbConso;
  nbCases = atoi(argv[3]);
  if (nbCases > NB_CASES_MAX)
    nbCases = NB_CASES_MAX;
  nbDepots = atoi(argv[4]);
  if (nbDepots < 0)
    nbDepots = -nbDepots;	  
  nbRetraits = atoi(argv[5]);
  if (nbRetraits < 0)
    nbRetraits = -nbRetraits;	  

  moniteurPC = new PCMonitorV1(nbCases);

  printf("Moniteur cree pour proteger %d cases\n", nbCases);

  /* Creation des nbProd producteurs et nbConso consommateurs */
  for (i = 0; i <  nbThds; i++) {
    if (i < nbProd) {
      paramThds[i].typeMsg = i%2;
      paramThds[i].rang = i;
      paramThds[i].nbFois = nbDepots;
      if ((etat = pthread_create(&idThdProd[i], NULL, producteur, &paramThds[i])) != 0)
        thdErreur(etat, "Creation producteur", etat);
#ifdef TRACE_THD
      printf("Creation thread prod %lu de rang %d -> %d/%d\n", idThdProd[i], i, paramThds[i].rang, nbProd);
#endif
    }
    else {
      paramThds[i].typeMsg = i%2;
      paramThds[i].rang = i - nbProd;
      paramThds[i].nbFois = nbRetraits;
      if ((etat = pthread_create(&idThdConso[i-nbProd], NULL, consommateur, &paramThds[i])) != 0)
        thdErreur(etat, "Creation consommateur", etat);
#ifdef TRACE_THD
      printf("Creation thread conso %lu de rang %d -> %d/%d\n", idThdConso[i-nbProd], i, paramThds[i].rang, nbConso);
#endif
    }
  }

  /* Attente de la fin des threads */
  for (i = 0; i < nbProd; i++) {
    if ((etat = pthread_join(idThdProd[i], (void **)&cr)) != 0)
      thdErreur(etat, "Join threads producteurs", etat);
    free(cr);
#ifdef TRACE_THD
    printf("Fin thread producteur de rang %d\n", i);
#endif
  }

  for (i = 0; i < nbConso; i++) {
    if ((etat = pthread_join(idThdConso[i], (void **)&cr)) != 0) 
      thdErreur(etat, "Join threads consommateurs", etat);
    free(cr);
#ifdef TRACE_THD
    printf("Fin thread consommateur de rang %d\n", i);
#endif
  }
    
#ifdef TRACE_THD
  printf ("\nFin de l'execution du main \n");
#endif

  return 0;
}
  
