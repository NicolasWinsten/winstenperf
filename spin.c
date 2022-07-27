#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>
#include <string.h>


int main(int argc, char **argv) {
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
        printf("%f\n", elapsed);
        return 0;        
}

