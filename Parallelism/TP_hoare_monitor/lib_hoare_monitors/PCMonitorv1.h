/* CB/UPS/IRIT
 * Producteur-consommateur - Moniteur - Specification (V1)
 * */

#ifndef PC_H
#define PC_H

#include "MONITEURS_HOARE/HoareMonitor.h"
#include "MONITEURS_HOARE/HoareCondition.h"

#define NB_CASES_MAX  20 

class PCMonitorV1 : public HoareMonitor {

  public :	
    typedef struct {
      char      info[80];
      unsigned  type;          // Message de 2 types (0/1 par exemple)
      unsigned  rangProd;      // Qui a produit le message
    } TypeMessage;

  protected :	
    TypeMessage buffer[NB_CASES_MAX];  	// Buffer
    unsigned iDepot;                    // Indice prochain depot
    unsigned iRetrait;			// Indice prochain retrait
    unsigned nbCasesBuffer;             // Taille effective du buffer

    // Version 1 : Version de base, pas de contraintes
    // Producteur bloque si buffer plein
    // Consommateur bloque si buffer vide
    HoareCondition *CVide, *CPleine;
    unsigned nbCasesPleines;                     

    void afficherBuffer (void);
    unsigned oppose (unsigned type);
    void depot (TypeMessage unMessage);
    void retrait (TypeMessage *unMessage);

  public : 
    PCMonitorV1(unsigned tailleBuffer);

    // Deposer/Retirer version de base - Le type n'est pas important
    void deposer (TypeMessage leMessage, unsigned rangProd);
    void retirer (TypeMessage *unMessage, unsigned rangConso);

};

#endif
