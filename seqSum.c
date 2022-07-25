#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>
#include <string.h>


int main(int argc, char **argv) {
        struct timeval startTime, stopTime;
        double elapsed;

        long arraySize = atol(argv[1]);

        long *a = (long *) malloc (sizeof(long) * arraySize);
        long i;

        for (i = 0; i < arraySize; i++)
                a[i] = i;


        gettimeofday(&startTime, NULL);
        long long total = 0;

        for (i = 0; i < arraySize; i++)
                total = total + a[i];
        gettimeofday(&stopTime, NULL);

        printf("%lld\n", total);
        elapsed = ((stopTime.tv_sec - startTime.tv_sec)*1000000 + (stopTime.tv_usec-startTime.tv_usec));
        printf("%f\n", elapsed);
        return 0;        
}

