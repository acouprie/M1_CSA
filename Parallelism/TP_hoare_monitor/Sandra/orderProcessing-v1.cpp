//
// Created by sandra on 12/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <time.h>

#include "xmasMonitor.h"

/// For the version 1 we define 4 employees (1 for each step)
#define NB_EMPLOYEES 4

pthread_mutex_t mutex_display = PTHREAD_MUTEX_INITIALIZER;

xmasMonitor *xmas;

/* codeErr : code returned by a primitive
 * msgErr  : error message, personalised
 * valErr  : returned value by the thread
 */
void thdError(int codeErr, string msgErr, int valeurErr) {
    int *retour = (int *)malloc(sizeof(int));
    *retour = valeurErr;
    std::cout << msgErr << ": " << codeErr << "(" << strerror(codeErr) << ")" << std::endl;
    pthread_exit(retour);
}

void applyStep (int idEmployee, string gift, int step, int counter) {
    pthread_mutex_lock(&mutex_display);
    std::cout << "Employee " << idEmployee << ": I'm working on the order " << gift << " from the counter " << counter << ".\n\tStep " << step;
    switch (step) {
        case 0:
            std::cout << " : Listing the ordered items ..." << std::endl;
            break;
        case 1:
            std::cout << " : Fetch the ordered items ..." << std::endl;
            break;
        case 2:
            std::cout << " : Wrap the items as Christmas presents ..." << std::endl;
            break;
        case 3:
            std::cout << " : Make the client pay ..." << std::endl;
            break;
    }
    pthread_mutex_unlock(&mutex_display);
}

void* client (void* args) {
    int idClient = *((int*) args);
    pthread_mutex_lock(&mutex_display);
    std::cout << "I'm the client " << idClient << ". I arrived to the mall" << std::endl;
    pthread_mutex_unlock(&mutex_display);
    xmas->order();
    pthread_mutex_lock(&mutex_display);
    std::cout << "I'm the client " << idClient << ". I'm leaving with my order ready! Youhou!" << std::endl;
    pthread_mutex_unlock(&mutex_display);
    return NULL;
}

void* employee (void* args) {
    int idEmployee = *((int*) args);
    int appliedStep = (idEmployee -1) % NB_STEPS; // -1 because idEmployee is from 1 to 4 instead of 0 to 3
    Order orderToProcess;
    int counter;
    while (1) {
        xmas->startStep(appliedStep, &orderToProcess, &counter);
        applyStep(idEmployee,orderToProcess.gift,appliedStep, orderToProcess.counter);
        xmas->finishStep(orderToProcess, counter);
    }
}

int main (int argc, char** argv) {
    srand(time(NULL));

    int etat;
    pthread_t idThdClient[NB_CLIENTS], idThdEmployee[NB_EMPLOYEES];

    if (argc != 1 ) {
        printf ("Usage: %s \n", argv[0]);
        exit(2);
    }
    pthread_mutex_init(&mutex_display, NULL);

    xmas = new xmasMonitor();

    /* Creation of NB_CLIENTS clients and NB_EMPLOYEES employees */
    for (int i = 0; i < NB_CLIENTS; i++) {
        if ((etat = pthread_create(&idThdClient[i], NULL, client, &i)) != 0)
            thdError(etat, "Creation client", etat);
    }
    for (int i = 0; i < NB_EMPLOYEES; i++) {
            if ((etat = pthread_create(&idThdEmployee[i], NULL, employee, &i)) != 0)
                thdError(etat, "Creation employee", etat);
    }

    /* Wait the end of threads */
    for (int i = 0; i < NB_CLIENTS; i++) {
        if ((etat = pthread_join(idThdClient[i], NULL)) != 0)
            thdError(etat, "Join threads clients", etat);
    }

    // To avoid a waiting program because of the while(1) loop on the employees funtion I change the Join loop for a Cancel one.
    // This function cancels the waiting employees when there is no client left. (Because we are after the join for the clients)
    for (int i = 0; i < NB_EMPLOYEES; i++) {
        if ((etat = pthread_cancel(idThdEmployee[i])) != 0)
            thdError(etat, "Cancel threads employee", etat);
    }

#ifdef TRACE
    printf ("\nYour shopping mall is about to close ! Thanks for coming !\n\tMERRY CHRISTMAS !\n");
#endif

    return 0;
}