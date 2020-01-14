#ifndef SEMAPHORE_H

#define SEMAPHORE_H

#include <pthread.h>
#include <semaphore.h>

class Semaphore {
  protected:
#ifdef MACOS
    char name[128];
#endif
    sem_t *sem;
  public:
    Semaphore(unsigned valInit = 0);
    Semaphore(const Semaphore &sem);
    ~Semaphore();
    Semaphore &operator=(const Semaphore &sem);
    void P();
    void V();
};
  
class Mutex {
  protected:
    pthread_mutex_t mutex;
  public:
    Mutex();
    Mutex(const Mutex &m);
    ~Mutex();
    Mutex &operator=(const Mutex &m);
    
    void P();
    void V();
};

#endif
