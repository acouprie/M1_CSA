#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "error.h"

void error(const char *message, unsigned exitValue) {
  int *adr = (int *)malloc(sizeof(int));	
  fprintf(stderr, "%s: %u\n", message, exitValue);
  pthread_exit((void*)adr);
}

