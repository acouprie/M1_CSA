/* CB/UPS/IRIT
 * Producteur-consommateur - Moniteur - Corps
 * */

#include "PCMonitorv1.h"
#include <string.h>

/*--------------------------------------------------*/
PCMonitorV1 :: PCMonitorV1 (unsigned tailleBuffer) {
  unsigned i;

  nbCasesBuffer = tailleBuffer;
  iDepot = 0;
  iRetrait = 0;
  for (i = 0; i < nbCasesBuffer; i++) {
    strcpy(buffer[i].info, "Message vide");
    buffer[i].type = 0;
    buffer[i].rangProd = -1;
  }
  nbCasesPleines = 0;

  CVide   = newCondition();
  CPleine = newCondition();
}

/*--------------------------------------------------*/
void PCMonitorV1 :: afficherBuffer (void) {
  unsigned i;

  printf("[ ");
  for (i = 0; i < nbCasesBuffer; i++) {
    printf("[T%d] %s (de %d), ", buffer[i].type,
           buffer[i].info, buffer[i].rangProd);
  }
  printf("]\n");
}

/*--------------------------------------------------*/
unsigned PCMonitorV1 :: oppose (unsigned type) {
  return (type + 1)%2;	
}

/*--------------------------------------------------*/
/*--------------------------------------------------*/
void PCMonitorV1 :: depot (TypeMessage unMessage) {
  strcpy(buffer[iDepot].info, unMessage.info);
  buffer[iDepot].type = unMessage.type;
  buffer[iDepot].rangProd = unMessage.rangProd;
  iDepot = (iDepot + 1) % nbCasesBuffer;
#ifdef TRACE_BUF
  afficherBuffer();
#endif
}

/*--------------------------------------------------*/
void PCMonitorV1 :: retrait (TypeMessage *unMessage) {
  strcpy(unMessage->info, buffer[iRetrait].info);
  unMessage->type = buffer[iRetrait].type;
  unMessage->rangProd = buffer[iRetrait].rangProd;
  iRetrait = (iRetrait + 1) % nbCasesBuffer;
#ifdef TRACE_BUF
  afficherBuffer();
#endif
}

/*--------------------------------------------------
 * V1 - Operation deposer
 * */
void PCMonitorV1 :: deposer (TypeMessage leMessage, unsigned rangProd) {
  // Debut E.M.	
  enter();

  // Bloque si buffer plein, attendre une case vide
  if (nbCasesPleines == nbCasesBuffer) {
    CVide->wait();
  }

  depot(leMessage);

  // Case pleine creee
  nbCasesPleines++;

  printf("\tProd %d : Message a ete depose = [T%d] %s (de %d)\n", 
         rangProd, leMessage.type, leMessage.info, leMessage.rangProd);

  // Case pleine creee, on reveille un eventuel consommateur
  CPleine->signal();

  // Fin E.M.	
  leave();
}  

/*--------------------------------------------------
 * V1 - Operation retirer 
 * */
void PCMonitorV1 :: retirer (TypeMessage *unMessage, unsigned rangConso) {
  enter();

  // Bloque si buffer vide, attendre case pleine
  if (nbCasesPleines == 0) {
    CPleine->wait();
  }
  
  retrait(unMessage);

  // Case vide creee
  nbCasesPleines--;

  printf("\t\tConso %d : Message a ete lu = [T%d] %s (de %d)\n", 
         rangConso, unMessage->type, unMessage->info, unMessage->rangProd);

  // Case vide creee, on reveille un eventuel producteur
  CVide->signal();

  leave();
}  
