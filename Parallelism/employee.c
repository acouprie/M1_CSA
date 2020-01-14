// 26/11/2019
typedef struct {
    int currentStep;
    char str[100];
    bool isProcessed; Optional: to know if a step is processed
} order;

Monitor HandleRequest {
    public:
    void order(void);
    void startStep(StepNumber aStep, Order *anOrder, CounterNumber *aCounter);
    void finishStep(Order *anOrder, CounterNumber aCounter);
    private:
    int checkWhere(int aStep);
    // State variables
    int nbFreeCounters = NB_COUNTERS;
    // Optional: Order orders[NB_COUNTERS]; to keep a trace of orders to know which one to process instead of isProcessed
    // Conditions
    counterFree // a queue for clients for having a counter
    orderBeingProcessed[NB_COUNTERS]; // a queue for clients to wait their order done
    employeeWaiting[NB_STEPS]; // employees waiting for working
}

Process Employee (StepNumber appliedStep) {
    while (1) {
        HandleRequests.startStep(appliedStep, &anOrderToProcess, &originalCounter) ;
        applyStep(appliedStep, &anOrderToProcess) ;
        HandleRequests.finishStep(anOrderToProcess, originalCounter);
        order(originalCounter).isProcessed = false;
    }
}

int checkWhere(int aStep) {
    int i = 0;
    for (i; i < NB_COUNTERS; i++) {
        if ((aStep==orders[i].currentStep) && (!order[i].isProcessed)) {
            break;
        }
    }
    return i;
}

void startStep(StepNumber aStep, Order *anOrder, CounterNumber *aCounter) {
    i = checkWhere();
    if (i == NB_COUNTERS) {
        employeeWaiting[aStep].wait();
        i=checkWhere();
    }
    orders[i].isProcessed = true;
    anOrder = orders[i];
    aCounter = i;
}

void finishStep(Order *anOrder, CounterNumber aCounter) {
    if(order->currentStep == NB_STEPS) {
        orderBeingProcessed[aCounter].signal();
    } else {
        anOrder->currentStep++;
        employeeWaiting[anOrder->currentStep].signal();
    }
}