#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
// Version 1
// Tow threads write on a screen 10 messages ("Im process 0", "Im process 1") in an alternate manner

pthread_mutex_t m1, m2 = PTHREAD_MUTEX_INITIALIZER;

void display_text()
{
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&m2);
        printf("\"Im process 1\"\n");
        pthread_mutex_unlock(&m1);
    }
}
void main()
{
    pthread_t p2;
    if(pthread_create(&p2, NULL, (void *(*)())display_text, NULL) == -1) {
        perror("Pbm fork\n");
    }

    pthread_mutex_lock(&m2);

    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&m1);
        printf("\"Im process 0\", ");
        pthread_mutex_unlock(&m2);
    }

}