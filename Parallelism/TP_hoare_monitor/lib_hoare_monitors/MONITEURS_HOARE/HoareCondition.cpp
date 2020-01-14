
#include "error.h"
#include "HoareCondition.h"
#include "HoareMonitor.h"
/*
    sem_t semCondition;
    unsigned nbWaiting;
    HoareMonitor &myHoareMonitor;
*/

HoareConditionBase :: HoareConditionBase(HoareMonitor &oneHoareMonitor) 
    : myHoareMonitor(oneHoareMonitor) {
  nbWaiting = 0;
}

HoareCondition::HoareCondition(HoareMonitor &oneHoareMonitor)
    : HoareConditionBase(oneHoareMonitor), semCondition(0) {
}

HoareCondition::HoareCondition(const HoareCondition &oneHoareCondition)
    : HoareConditionBase(oneHoareCondition.myHoareMonitor), semCondition(0){
  error("HoareMonitor copy constructor not allowed", 2);
}

HoareCondition::~HoareCondition(){
}

void HoareCondition::wait(){
  nbWaiting++;
  myHoareMonitor.leave();
  semCondition.P();
  nbWaiting--;    
}

void HoareCondition::signal(){
  if (nbWaiting) {
    myHoareMonitor.cptUrgent++;
    semCondition.V();
    myHoareMonitor.urgent.P();
    myHoareMonitor.cptUrgent--;
  }
}


//------------------------
HoareConditionWithPriority::HoareConditionWithPriority(HoareMonitor &oneHoareMonitor, unsigned nbPriorities)
    : HoareConditionBase(oneHoareMonitor) {
  this->nbPriorities = nbPriorities;
  semCondition = new Semaphore[nbPriorities];
  nbWaitingByPriority = new unsigned[nbPriorities];
  for (unsigned c = 0; c < nbPriorities; c++)
    nbWaitingByPriority[c] = 0;
}

HoareConditionWithPriority::HoareConditionWithPriority(const HoareConditionWithPriority &oneHoareConditionWithPriority)
    : HoareConditionBase(oneHoareConditionWithPriority.myHoareMonitor){
  error("HoareConditionWithPriority copy constructor not allowed", 2);
}

HoareConditionWithPriority::~HoareConditionWithPriority(){
  delete [] semCondition;
  delete [] nbWaitingByPriority;
}

void HoareConditionWithPriority::wait(unsigned priority){
  if (priority >= nbPriorities)
    error("HoareConditionWithPriority error wait priority", 3);
  nbWaiting++;
  nbWaitingByPriority[priority]++;
  myHoareMonitor.leave();
  semCondition[priority].P();
  nbWaiting--;    
  nbWaitingByPriority[priority]--;
}

void HoareConditionWithPriority::signal(){
  if (nbWaiting) {
    myHoareMonitor.cptUrgent++;
    unsigned priority = 0;
    while (nbWaitingByPriority[priority] == 0) 
      priority++;
    semCondition[priority].V();
    myHoareMonitor.urgent.P();
    myHoareMonitor.cptUrgent--;
  }
}
