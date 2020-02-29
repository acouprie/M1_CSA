#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_1(void *arg){
    printf("We're inside the thread.\n");
    /* Just to remove the warning */
    (void) arg;
    pthread_exit(NULL);
}
int main(void){
    int i;
    pthread_t threads[3];
    printf("Before the creation of the thread.\n");
    for(i = 0; i < 3; i++) { /* create threads */
        if (pthread_create(&threads[i], NULL, thread_1, (void *)i)) {
            printf("Can not create a thread\n");
            exit(1);
        }
    }
    for (i = 0; i < 3; i++) { /* wait for terminate a threads */
        pthread_join(threads[i], NULL);
    }
    printf("After the creation of the thread.\n");
    return EXIT_SUCCESS;
}