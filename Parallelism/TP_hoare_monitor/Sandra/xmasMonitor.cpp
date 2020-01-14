//
// Created by sandra on 12/12/2019.
//

#include "xmasMonitor.h"

/// Monitor's constructor
xmasMonitor :: xmasMonitor () {
    client = newCondition();
    for (int i = 0; i < NB_COUNTERS; ++i) {
        waitingOrder[i] = newCondition();
        countersFree[i] = true;
        ordersList[i].currentStep = -1;
        ordersList[i].isProcessed = false;
    }
    for (int i = 0; i < NB_STEPS; ++i) {
        employees[i] = newCondition();
    }
}

/// Returns the first free counter
int xmasMonitor :: getFreeCounter () {
    int i = 0;
    while (i<NB_COUNTERS) {
        if (countersFree[i]){
            countersFree[i] = false;
            return i;
        }
        ++i;
    }
    return -1;
}

/// Create the new order
void xmasMonitor :: createOrder(Order* order, int counter) {
    string giftList[5] = {"Toy","Console","Game","Clothes","Furniture"};
    order->gift = giftList[rand()%5];
    order->currentStep = 0;
    order->counter = counter;
    order->isProcessed = false;
}

/// Procedure of an order : Client arrives, process order, client leaves
void xmasMonitor :: order() {
    int counter;
    enter();
    // Check if a counter is free
    if (nbFreeCounters == 0)
        client->wait();
    -- nbFreeCounters;
    counter = getFreeCounter();

    // When we have a counter we prepare the order
    createOrder(&ordersList[counter],counter);

    // We wake up the first employee to work on our order
    employees[0]->signal();

    // We wait until the order is ready
    waitingOrder[counter]->wait();

    // We free the counter
    countersFree[counter] = true;
    ++ nbFreeCounters;
    client->signal();
    leave();
}

/// Employee check if there is an order not processed, if there is he work on it, otherwise he waits
void xmasMonitor :: startStep(int appliedStep, Order *anOrder, int *aCounter) {
    enter();

    int i = checkWhere(appliedStep);
    if (i == NB_COUNTERS) {
        employees[appliedStep]->wait();
        i=checkWhere(appliedStep);
    }
    ordersList[i].isProcessed = true;
    *anOrder = ordersList[i];
    *aCounter = i;

    leave();
}

/// Empolyee check if last step, if it is signal the end of the order processing otherwise signal the next employee
void xmasMonitor :: finishStep(Order anOrder, int aCounter) {
    enter();

    if(anOrder.currentStep == NB_STEPS-1)
        waitingOrder[aCounter]->signal();
    else {
        ordersList[aCounter].isProcessed = false;
        ++ordersList[aCounter].currentStep;
        employees[ordersList[aCounter].currentStep]->signal();
    }

    leave();
}

/// First order not processed at the step "aStep"
int xmasMonitor :: checkWhere(int appliedStep) {
    for (int i = 0; i < NB_COUNTERS; ++i) {
        if ((appliedStep == ordersList[i].currentStep) && (!ordersList[i].isProcessed))
            return i;
    }
    return NB_COUNTERS;
}