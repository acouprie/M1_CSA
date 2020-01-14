#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
// Version 2
// Generalise the procedure with P threads.
#define NB_PROCESS 10

static pthread_mutex_t mutexes[NB_PROCESS];
static pthread_t processes[NB_PROCESS];

int display_text(int i) {
    int j = 0;
    while (j < 10)
    {
        j++;
        pthread_mutex_lock(&mutexes[i]);
        printf("I am Process %d\n", i);
        pthread_mutex_unlock(&mutexes[(i+1) % NB_PROCESS]);
    }
}

void main()
{
    int i = 1;
    pthread_mutex_init(&mutexes[0], NULL);
    for (i; i < NB_PROCESS; i++) {
        pthread_mutex_init(&mutexes[i], NULL);
        pthread_mutex_lock(&mutexes[i]);
        if(pthread_create(&processes[i], NULL, (void *(*)())display_text, i) == -1) {
            perror("Pbm fork\n");
        }
    }
}