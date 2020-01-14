#include "mall.h"

MallMonitor :: MallMonitor () {
    counterFree = newCondition();
    for (int i = 0; i < NB_COUNTER_MAX; i++)
    {
        orderBeingProcessed[i] = newCondition();
    }
    for (int i = 0; i < NB_STEPS_MAX; i++)
    {
        employeeWaiting[i] = newCondition();
    }
}

int MallMonitor :: getFreeCounter () {
    int i = 0;
    while (i < NB_COUNTER_MAX)
    {
        if(countersFree[i]) {
            countersFree[i] = false;
            return i;
        } 
        i++;
    }
    return -1;
}

void MallMonitor :: order() {
    int counter;
    enter();
    if (nbFreeCounters == 0)
    {
        counterFree->wait();
    }
    nbFreeCounters--;
    counter = getFreeCounter();
    int i = 0;
    for (i; i < NB_COUNTER_MAX; i++)
    {
        if (orderBeingProcessed[i]->length() == 0)
        {
            break;
        }
    }
    Order o;
    o.currentStep = 0;
    o.str = "Order a Christmas gift";
    o.isProcessed = false;
    employeeWaiting[0]->signal();
    orderBeingProcessed[i]->wait();
    nbFreeCounters++;
    counterFree->signal();
    leave();
}

int MallMonitor :: checkWhere(int aStep) {
    int i = 0;
    for (i; i < NB_COUNTERS; i++) {
        if ((aStep==orders[i].currentStep) && (!orders[i].isProcessed)) {
            break;
        }
    }
    return i;
}

void MallMonitor :: startStep(int aStep, Order &anOrder, int &aCounter) {
    enter();
    int i = checkWhere(aStep);
    if (i == NB_COUNTERS) {
        employeeWaiting[aStep]->wait();
        i = checkWhere(aStep);
    }
    orders[i].isProcessed = true;
    anOrder = orders[i];
    aCounter = i;
    leave();
}

void MallMonitor :: finishStep(Order &anOrder, int aCounter) {
    enter();
    if(anOrder.currentStep == NB_STEPS) {
        orderBeingProcessed[aCounter]->signal();
    } else {
        anOrder.currentStep++;
        cout << "Current step of order " << &anOrder << " : " << anOrder.currentStep << endl;
        employeeWaiting[anOrder.currentStep]->signal();
        orders[aCounter].isProcessed = false;
    }
    leave();
}
