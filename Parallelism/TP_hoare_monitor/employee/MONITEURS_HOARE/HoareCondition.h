#ifndef HOARE_CONDITION_H

#define HOARE_CONDITION_H

#include <pthread.h>

#include "sem.h"

class HoareMonitor;

class HoareConditionBase {
   // Toutes les methodes de la classe HoareMonitor peuvent acceder
   // a tous les elements de cette classe
  friend class HoareMonitor;
  protected:     // Elements inaccessibles depuis l'exterieur de la classe, 
                 // sauf si c'est une classe fille

    // Le moniteur auquel est lie cette var. "condition"
    HoareMonitor &myHoareMonitor;
    // Le nombre de threads en attente sur cette var. "condition"
    unsigned nbWaiting;
    
  public:   // Elements accessibles depuis l'exterieur de la classe
    // Constructeur et destructeur de la classe
    HoareConditionBase(HoareMonitor &itsHoareMonitor);
    virtual ~HoareConditionBase() {};
  
    // c.signal()
    virtual void signal() = 0;  
    // Acces au nombre de threads en attente sur la var. "condition"
    unsigned length() { // c.length()
       return nbWaiting; 
    }  
};

// Classe pour definir des var. "condition" sans priorite
// La classe herite de la classe "de base"
class HoareCondition : public HoareConditionBase {
   // Toutes les methodes de la classe HoareMonitor peuvent acceder
   // a tous les elements de cette classe
  friend class HoareMonitor;
  protected:   // Elements inaccessibles depuis l'exterieur de la classe, 
              // sauf si c'est une classe fille
    // Semaphore permettant de bloquer les threads lorsqu'ils 
    // executent c.wait(); 
    Semaphore semCondition;
    
  public:
    // Constructeurs et destructeur
    // En partant d'un moniteur
    HoareCondition(HoareMonitor &itsHoareMonitor);
    // En partant d'une autre var. "condition"
    HoareCondition(const HoareCondition &oneHoareCondition);
    virtual ~HoareCondition();
    
    // Les 2 operations sur la var. "condition"
    void wait();
    void signal();
};

// Classe pour definir des var. "condition" a priorite
// La classe herite de la classe "de base"
class HoareConditionWithPriority : public HoareConditionBase {
  friend class HoareMonitor;
  protected:
    // De l'exterieur, on n'aura pas acces aux variables permettant
    // de gerer les operations publiques sur cette var. "condition"

    // Un semaphore par priorite p pour bloquer les threads lorsqu'ils
    // executent c.wait(p);
    Semaphore *semCondition;
    // Nombre de threads en attente par priorite
    unsigned *nbWaitingByPriority;
    
    // Nombre de priorites 
    unsigned nbPriorities;
    
  public:
    // Constructeurs et destructeur 
    // En partant d'une moniteur et d'un nombre de priorites
    HoareConditionWithPriority(HoareMonitor &itsHoareMonitor, unsigned nbPriorities);
    // En partant d'une autre var. "condition" avec priorite
    HoareConditionWithPriority(const HoareConditionWithPriority &oneHoareConditionWithPriority);
    virtual ~HoareConditionWithPriority();

    // Les 2 operations possibles sur la var. "condition"
    // wait avec priorite - 0 = la + forte
    void wait(unsigned priority);
    void signal();
};
#endif
