#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "error.h"
#include "HoareMonitor.h"
#include "HoareCondition.h"
#include "sem.h"

/*
 pthread_mutex_t mutex;
 sem_t urgent;
 List listCondition;
*/
    
HoareMonitor::HoareMonitor() : urgent(0){
  cptUrgent = 0;
}
    
HoareMonitor::HoareMonitor(const HoareMonitor &oneMonitor) : urgent(0) {
  error("HoareMonitor copy constructor not allowed", 3);
}
    
HoareMonitor::~HoareMonitor() {
  HoareConditionBase *oneCondition;
  while ((oneCondition = (HoareConditionBase *)listCondition.getlast()) != 0)
    delete oneCondition;
}
    
void HoareMonitor::enter(){
  mutex.P();
}
    
void HoareMonitor::leave(){
  if (cptUrgent)
    urgent.V();
  else
    mutex.V();
}
    
HoareCondition *HoareMonitor::newCondition(){
  HoareCondition *oneCondition = new HoareCondition(*this);
  listCondition.append(oneCondition);
  return oneCondition;
}

HoareConditionWithPriority *HoareMonitor::newConditionWithPriority(unsigned nbPriorities){
  HoareConditionWithPriority *oneCondition = new HoareConditionWithPriority(*this, nbPriorities);
  listCondition.append(oneCondition);
  return oneCondition;
}
    
