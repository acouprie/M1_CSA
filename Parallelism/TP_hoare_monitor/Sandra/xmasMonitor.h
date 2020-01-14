//
// Created by sandra on 12/12/2019.
//

#include <string.h>
#include <stdlib.h>

#include "MONITEURS_HOARE/HoareMonitor.h"
#include "MONITEURS_HOARE/HoareCondition.h"

#ifndef PDS_XMASMONITOR_H
#define PDS_XMASMONITOR_H

/// For the 2 versions we define 8 clients, 3 counters and 4 steps
#define NB_COUNTERS 3
#define NB_STEPS 4
#define NB_CLIENTS 8



typedef struct {
    int currentStep;
    int counter;
    bool isProcessed;
    string gift;
} Order;

class xmasMonitor : public HoareMonitor {
public:
    void order();
    void startStep(int aStep, Order *anOrder, int *aCounter);
    void finishStep(Order anOrder, int aCounter);
    xmasMonitor ();

private:
    int checkWhere(int aStep);
    int getFreeCounter();
    void createOrder(Order* order, int counter);
    int nbFreeCounters = NB_COUNTERS;
    Order ordersList [NB_COUNTERS];
    bool countersFree [NB_COUNTERS];

protected:
    HoareCondition *client, *waitingOrder[NB_COUNTERS], *employees[NB_STEPS];
};


#endif //PDS_XMASMONITOR_H
