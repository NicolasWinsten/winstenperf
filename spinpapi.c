#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>
#include <string.h>
#include <papi.h>

int main(int argc, char **argv) {

  int retval;

  retval=PAPI_library_init(PAPI_VER_CURRENT);
  if (retval!=PAPI_VER_CURRENT) {
    fprintf(stderr,"Error initializing PAPI! %s\n",
    PAPI_strerror(retval));
    return 0;
  }

  int eventset=PAPI_NULL;

  retval=PAPI_create_eventset(&eventset);
  if (retval != PAPI_OK) {
    fprintf(stderr, "Error creating event set: %s\n", PAPI_strerror(retval));
    return 0;
  }

  retval=PAPI_add_named_event(eventset, "PAPI_TOT_CYC");
  if (retval != PAPI_OK) {
    fprintf(stderr, "Error adding event: %s\n", PAPI_strerror(retval));
    return 0;
  }

  retval=PAPI_add_named_event(eventset, "PAPI_TOT_INS");
  if (retval != PAPI_OK) {
    fprintf(stderr, "Error adding event: %s\n", PAPI_strerror(retval));
    return 0;
  }

  PAPI_reset(eventset);
  retval=PAPI_start(eventset);
  if (retval != PAPI_OK) {
    fprintf(stderr, "Error starting CUDA: %s\n", PAPI_strerror(retval));
    return 0;
  }

        struct timeval startTime, stopTime;
        double elapsed;

        long arraySize = atol(argv[1]);
        long times = atol(argv[2]);

        long i, j;
    
        gettimeofday(&startTime, NULL);
        for (j = 0; j < times; j++)
        for (i = 0; i < arraySize; i++);
        gettimeofday(&stopTime, NULL);
        elapsed = ((stopTime.tv_sec - startTime.tv_sec)*1000000 + (stopTime.tv_usec-startTime.tv_usec));
       // printf("%f\n", elapsed);
       
  long long results[2]; 
  retval=PAPI_stop(eventset, results);        
  if (retval != PAPI_OK) {
    fprintf(stderr, "Error stopping: %s\n", PAPI_strerror(retval));
    return 0;
  }
  printf("PAPI_TOT_CYC: %lld\n", results[0]);
  printf("PAPI_TOT_INS: %lld\n", results[1]);


  return 0; 
}

