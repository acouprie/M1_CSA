#include <unistd.h>
#include <string.h>

#include "mall.h"

MallMonitor *monitorMall;

typedef struct {                
    int appliedStep;
} Parameters;

void thdErreur(int codeErr, const char *msgErr, int valeurErr) {
    int *retour = (int *)malloc(sizeof(int));
    *retour = valeurErr;
    fprintf(stderr, "%s: %d soit %s \n", msgErr, codeErr, strerror(codeErr));
    pthread_exit(retour);
}

void applyStep(int astep, MallMonitor::Order &anOrder) {
    sleep(1);
}

void * employee(void *arg) {
    cout << "Hire an employee ! " << endl;
    Parameters *param = (Parameters *)arg;

    int appliedStep = param->appliedStep;
    int originalCounter;
    MallMonitor::Order order;
    while (1)
    {
        monitorMall->startStep(appliedStep, order, originalCounter) ;
        applyStep(appliedStep, order) ;
        monitorMall->finishStep(order, originalCounter);
    }
}

void * client (void *arg) {
    cout << "Client go to mall" << endl;
    monitorMall->order();
    cout << "Client go to home" << endl;
}

int main(int argc, char *argv[]) {
    unsigned i, etat;
    unsigned nbThds, nbEmployee, nbClient, nbCounters, nbSteps;
    int *cr;
    Parameters paramThds[NB_EMPLOYEE_MAX + NB_CLIENT_MAX];
    pthread_t idThdProd[NB_EMPLOYEE_MAX], idThdConso[NB_CLIENT_MAX];

    if (argc <= 3) {
     printf ("Usage: %s <Nb Employee <= %d> <Nb Client <= %d> <Nb Counters <= %d> <Nb Steps <= %d> \n", 
            argv[0], NB_EMPLOYEE_MAX, NB_CLIENT_MAX, NB_COUNTER_MAX, NB_STEPS_MAX);
      exit(2);
    }

    nbEmployee = atoi(argv[1]);
    if (nbEmployee > NB_EMPLOYEE_MAX)
        nbEmployee = NB_EMPLOYEE_MAX;
    nbClient = atoi(argv[2]);
    if (nbClient > NB_CLIENT_MAX)
        nbClient = NB_CLIENT_MAX;
    nbThds = nbEmployee + nbClient;
    nbCounters = atoi(argv[3]);
    if (nbCounters > NB_COUNTER_MAX)
        nbCounters = NB_COUNTER_MAX;
    nbSteps = atoi(argv[4]);
    if (nbSteps > NB_STEPS_MAX)
        nbSteps = NB_STEPS_MAX;

    monitorMall = new MallMonitor();
    /* Creation des nbEmployee employee et nbClient client */
    for (i = 0; i <  nbThds; i++) {
        if (i < nbEmployee) {
            paramThds[i].appliedStep = i;
            if ((etat = pthread_create(&idThdProd[i], NULL, employee, &paramThds[i])) != 0)
                thdErreur(etat, "Create employee ", etat);
            #ifdef TRACE_THD
                printf("Create thread employee %lu de rang %d -> %d/%d\n", idThdProd[i], i, nbEmployee);
            #endif
        } else {
        if ((etat = pthread_create(&idThdConso[i-nbEmployee], NULL, client, &paramThds[i])) != 0)
            thdErreur(etat, "Create client ", etat);
        #ifdef TRACE_THD
            printf("Create thread client %lu de rang %d -> %d/%d\n", idThdConso[i-nbEmployee], i, nbClient);
        #endif
        }
    }

  /* Attente de la fin des threads */
    for (i = 0; i < nbEmployee; i++) {
        if ((etat = pthread_join(idThdProd[i], (void **)&cr)) != 0)
            thdErreur(etat, "Join threads employee", etat);
        free(cr);
        #ifdef TRACE_THD
            printf("End thread employee %d\n", i);
        #endif
    }

    for (i = 0; i < nbClient; i++) {
        if ((etat = pthread_join(idThdConso[i], (void **)&cr)) != 0) 
            thdErreur(etat, "Join threads clients", etat);
        free(cr);
        #ifdef TRACE_THD
            printf("End thread client %d\n", i);
        #endif
    }
    
    #ifdef TRACE_THD
        printf ("\nEnd execution of main \n");
    #endif

    return 0;
}