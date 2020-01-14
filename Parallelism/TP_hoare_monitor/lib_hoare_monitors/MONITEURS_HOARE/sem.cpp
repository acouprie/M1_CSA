#include <stdio.h>

#include "sem.h"
#include "error.h"

Semaphore::Semaphore(unsigned valInit){
#ifdef MACOS
  sprintf(name,"SEM_%lx", (long)&sem);
  sem = sem_open(name, O_CREAT | O_EXCL, 0666, valInit);
  if (sem == SEM_FAILED)
    error("Semaphore::Semaphore error sem_open", 1);  
#else
  sem = new sem_t;
  if (sem_init(sem, 0, valInit) != 0)
    error("Semaphore::Semaphore error sem_init", 1);  
#endif
}
  
Semaphore::Semaphore(const Semaphore &sem){
  error("Semaphore::Semaphore(const Semaphore &sem) error ", 2);
}

Semaphore &Semaphore::operator=(const Semaphore &sem){
  error("Semaphore::operator=(const Semaphore &sem) error ", 3);
  return *this;
}

Semaphore::~Semaphore() {
#ifdef MACOS
  int ret = sem_close(sem);
  if (ret) 
    error("Semaphore::~Semaphore error sem_close", 4);
    
  if (sem_unlink(name))
    error("Semaphore::~Semaphore error sem_unlink", 4);
#else
 if (sem_destroy(sem) != 0)
    error("Semaphore::~Semaphore error sem_destroy", 4);
#endif
}
    
void Semaphore::P(){
  if (sem_wait(sem) != 0)
    error("wait sem in P error", 5);
}

void Semaphore::V(){
  if (sem_post(sem) != 0)
    error("post sem in V error", 6);
}


Mutex::Mutex() {
  if (pthread_mutex_init(&mutex, 0) != 0)
    error("Mutex::Mutex mutex_init error", 1);
}

Mutex::~Mutex() {
  if (pthread_mutex_destroy(&mutex) != 0)
    error("Mutex::~Mutex mutex_destroy error", 2);
}

Mutex::Mutex(const Mutex &mutex){
  error("Mutex::Mutex(const Mutex &mutex) error ", 3);
}

Mutex &Mutex::operator=(const Mutex &mutex){
  error("Mutex::operator=(const Mutex &mutex) error ", 4);
  return *this;
}

void Mutex::P(){
  if (pthread_mutex_lock(&mutex) != 0)
    error("lock mutex in P error", 5);
}

void Mutex::V(){
  if (pthread_mutex_unlock(&mutex) != 0)
    error("unlock mutex in V error", 6);
}

