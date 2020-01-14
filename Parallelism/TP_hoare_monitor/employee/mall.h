#include <string.h>
#include <stdlib.h>

#ifndef PC_H
#define PC_H

#include "MONITEURS_HOARE/HoareMonitor.h"
#include "MONITEURS_HOARE/HoareCondition.h"

#define NB_COUNTER_MAX 10
#define NB_STEPS_MAX 10
#define NB_CLIENT_MAX 10
#define NB_EMPLOYEE_MAX 10
#define NB_STEPS 1
#define NB_COUNTERS 10

class MallMonitor : public HoareMonitor {
    public:
    typedef struct {
        int currentStep = 0;
        string str = "This is an order";
        bool isProcessed = false;
    } Order;
    Order orders[NB_COUNTER_MAX];
    bool countersFree[NB_COUNTER_MAX];

    void order();
    void startStep(int aStep, Order &anOrder, int &aCounter);
    void finishStep(Order &anOrder, int aCounter);
    MallMonitor();

    private:
    int getFreeCounter();
    int checkWhere(int aStep);

    protected:
    // State variables
    int nbFreeCounters = NB_COUNTER_MAX;
    // Optional: Order orders[NB_COUNTERS]; to keep a trace of orders to know which one to process instead of isProcessed
    // Conditions
    HoareCondition *counterFree; // a queue for clients for having a counter
    HoareCondition *orderBeingProcessed[NB_COUNTER_MAX]; // a queue for clients to wait their order done
    HoareCondition *employeeWaiting[NB_STEPS_MAX]; // employees waiting for working
};

#endif
