#ifndef HOARE_BASE_MONITOR_H

#define HOARE_BASE_MONITOR_H

#include <pthread.h>

#include "sem.h"
#include "List.h"

class HoareCondition;
class HoareConditionWithPriority;
class List;

// Classe "Moniteur de Hoare"
class HoareMonitor {
  
  // Classes ayantile privilege d'acces a
  // tous les composants de la classe HoareMonitor  	
  friend class HoareCondition;
  friend class HoareConditionWithPriority;

  // Membres "protected" : non accessibles de l'exterieur 
  // SAUF pour les classes filles
  // Le "moniteur de Hoare" a coder sera une classe fille
  // (heritera) de cette classe et pourra les utiliser
  protected: 
    // Mutex assurant l'E.M. des operations
    // A ne pas utiiser dans le "moniteur de Hoare" a coder
    Mutex mutex;
    // Pour la "suspension" des threads ayant execute un c.signal()
    Semaphore urgent;
    // Nombre de threads "suspendus" apres un c.signal() 
    // et donc prioritaires pour reprendre le controle du moniteur
    unsigned cptUrgent;
    // Liste des variables "condition" creees pour ce moniteur 
    // pour les detruire automatiquement lorsque ce moniteur est detruit 
    List listCondition;
    
  protected:
    // Constructeurs et destructeur
    // A partir de rien
    HoareMonitor();
    // A partir d'un autre "moniteur de Hoare"
    HoareMonitor(const HoareMonitor &oneMonitor);
    ~HoareMonitor();
    
    // Pour mettre en place l'E.M d'une operation du moniteur
    // (qui sera utilisee par les threads pour se synchroniser)

    // Entrer dans le moniteur (operation en E.M)
    void enter();
    // Quitter le moniteur (operation en E.M)
    void leave();
    
    // Les var. conditions liees a ce "moniteur de Hoare"

    // Creer une variable "condition" normale pour realiser 
    // la synchronisation dans ce moniteur
    HoareCondition *newCondition();
    // Creer une variable "condition" avec priorite pour realiser 
    // la synchronisation dans ce moniteur
    HoareConditionWithPriority *newConditionWithPriority(unsigned nbPriorities);
};

#endif
